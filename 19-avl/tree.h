//======================================================================
//  File:        tree.h
//  Author:      Timothy A. Budd
//  Description: This file contains the interface of the tree
//               classes.
// Taken from:
//  http://web.engr.oregonstate.edu/~tgd/classes/539-old/programs/tree.h
//  Copyright (c) 1992 by Timothy A. Budd.  All Rights Reserved.
//	may be reproduced for any non-commercial purpose
//======================================================================

#ifndef TREE_H
#define TREE_H

# include <assert.h>
# include "iterator.h"
# include "vector.h"
# include "list.h"
# include "stack.h"



//----------------------------------------------------------------------
//	class node
//		a single node from a binary tree
//----------------------------------------------------------------------

template <class T> class node
{
public:
    // constructors
    node   (T value);
    node   (T value, node * left, node * right);

    // public data area for value field
    T         value;

    // duplicate tree rooted at this node
    virtual node * copy() const;

    // release entire tree at this node
    void      release();

    // accessing, changing child nodes
    node * left() const;
    void      left(node * l);

    node * right() const;
    void      right(node * r);

    // data areas
    node * leftptr;
    node * rightptr;
};



//----------------------------------------------------------------------
//	class searchTree
//		collection designed for fast insertion, test, and
//              removal operations
//----------------------------------------------------------------------

template <class T> class searchTreeIterator;

template <class T> class searchTree
{
public:
    // constructor
    searchTree();
    searchTree(searchTree<T> &);
    virtual ~searchTree();

    // protocol for search trees
    virtual void  add(T value);
    void          deleteAllValues();
    int           includes(T value) const;
    int           isEmpty() const;
    virtual void  remove(T value);

protected:
    // data areas
    node<T> *     root;

    friend class  searchTreeIterator<T>;

    // method used internally to delete top node
    node<T> *     removeTop(node<T> *);
};


//----------------------------------------------------------------------
//	class inorderTreeTraversal
//              perform an inorder traversal of a binary tree
//----------------------------------------------------------------------

template <class T> class inorderTreeTraversal : public iterator<T>
{
public:
    // constructor
    inorderTreeTraversal(node<T> * initialRoot);
    inorderTreeTraversal(const inorderTreeTraversal & x);
    inorderTreeTraversal() : itrstack(32) { }

    // reimplement iterator protocol
    virtual int     init();
    virtual int     operator !();
    virtual T       operator ()();
    virtual void    operator =(T val);
    virtual int     operator ++();

    // also permit changing the root
    void            setRoot(node<T> * newRoot);

private:
    // data ares
    node<T> *            root;
    //stackList<node<T> *> itrstack;
    stackVector<node<T> *> itrstack;

    // internal method to slide down left subtree
    void            slideLeft(node<T> *);
};



//----------------------------------------------------------------------
//	class searchTreeIterator
//		iterator for search trees
//----------------------------------------------------------------------

template <class T> class searchTreeIterator
    : public inorderTreeTraversal<T>
{
public:
    // constructor
    searchTreeIterator(searchTree<T> & tree);

    // initialize iteration, find first element
    virtual int      init();

private:
    // store reference to the entire tree
    searchTree<T> &  base;
};



//----------------------------------------------------------------------
//	class avlNode
//		a single node in an avl tree
//----------------------------------------------------------------------

template <class T> class avlNode : public node<T>
{
public:
    // constructor
    avlNode(T value);
    avlNode(T, node<T> *, node<T> *);

    // redefine access to left and right children
    void            left(avlNode * v);
    avlNode *    left() const;
    void            right(avlNode * v);
    avlNode *    right() const;

    // insert a new node into tree
    avlNode *    add(T value);

    // remove an item from tree, setting reference to containing node
    avlNode *    remove(T, avlNode * &);

    // duplicate tree
    virtual node<T> *    copy() const;

private:
    short           balFac;    // balance factor, either -1, 0 or 1

    avlNode *    singleRotateLeft();
    avlNode *    singleRotateRight();
    avlNode *    restoreLeftBalance(int);
    avlNode *    restoreRightBalance(int);
    avlNode *    balance();
    avlNode *    removeLeftmostDescendent(avlNode<T> * &);
};



//----------------------------------------------------------------------
//	class avlTree
//              a form of binary search tree that maintains
//              the height balance property
//              thus ensuring efficient operation
//----------------------------------------------------------------------

template <class T> class avlTree : public searchTree<T>
{
public:
    // insertion procedure
    virtual void    add(T value);

    // removal procedure
    virtual void    remove(T value);

private:
    avlNode<T> *    rootptr();
};



//----------------------------------------------------------------------
//	class postorderTreeTraversal
//              perform a post order traversal of a binary tree
//----------------------------------------------------------------------

template <class T> class postorderTreeTraversal : public iterator<T>
{
public:
    // constructor
    postorderTreeTraversal(node<T> * root);
    postorderTreeTraversal(const postorderTreeTraversal & x);

    // reimplement iterator protocol
    virtual int     init();
    virtual int     operator !();
    virtual T       operator ()();
    virtual void    operator =(T val);
    virtual int     operator ++();

    // also permit changing the root
    void            setRoot(node<T> * root);

private:
    // data areas
    node<T> *            root;
    stackList<node<T> *> itrstack;

    // internal method used to stack children of a node
    void            stackChildren(node<T> *);
};



//----------------------------------------------------------------------
//	class preorderTreeTraversal
//              perform a preorder traversal of a binary tree
//----------------------------------------------------------------------

template <class T> class preorderTreeTraversal : public iterator<T>
{
public:
    // constructor
    preorderTreeTraversal(node<T> * root);
    preorderTreeTraversal(const preorderTreeTraversal &);

    // iterator protocol
    virtual int     init();
    virtual int     operator !();
    virtual T       operator ()();
    virtual void    operator =(T val);
    virtual int     operator ++();

    // in addition, permit user to set new root
    void            setRoot(node<T> * root);

private:
    // data areas
    node<T> *            root;
    stackList<node<T> *> itrstack;
};

//----------------------------------------------------------------------
//	class levelorderTreeTraversal
//              perform a level order traversal of a binary tree
//----------------------------------------------------------------------

# include "queue.h"

template <class T> class levelorderTreeTraversal : public iterator<T>
{
public:
    // constructor
    levelorderTreeTraversal(node<T> * root);
    levelorderTreeTraversal(const levelorderTreeTraversal &);

    // reimplement iterator protocol
    virtual int     init();
    virtual int     operator !();
    virtual T       operator ()();
    virtual void    operator =(T val);
    virtual int     operator ++();

    // also permit changing the root
    void            setRoot(node<T> * root);

private:
    // data areas
    node<T> *            root;
    queueList< node<T> *> itrqueue;
};



//----------------------------------------------------------------------
//	class node implementation
//----------------------------------------------------------------------

template <class T> node<T>::node(T val)
    : value(val), leftptr(0), rightptr(0)
{
    // no further initialization
}


template <class T> node<T>::node(T val, node<T> * l, node<T> * r)
    : value(val), leftptr(l), rightptr(r)
{
    // no further initialization
}


template <class T> node<T> * node<T>::copy() const
{
    // return copy of tree rooted at node
    node<T> * newLeft;
    node<T> * newRight;

    // duplicate left child
    if (leftptr != 0)
	newLeft = leftptr->copy();
    else
        newLeft = 0;

    // duplicate right child
    if (rightptr != 0)
	newRight = rightptr->copy();
    else
	newRight = 0;

    // duplicate node, check that allocation worked
    node<T> * newptr = new node<T>(value, newLeft, newRight);
    assert(newptr != 0);

    // return new node
    return newptr;
}


template <class T> void node<T>::release()
{
    // release memory associated with children
    if (leftptr)
    {
	// release left child
	leftptr->release();
	delete leftptr;
	leftptr = 0;
    }

    if (rightptr)
    {
	// release right child
	rightptr->release();
	delete rightptr;
	rightptr = 0;
    }
}


template <class T> node<T> * node<T>::left() const
{
    // return the left node
    return leftptr;
}


template <class T> void node<T>::left(node<T> * l)
{
    // set the left node
    leftptr = l;
}


template <class T> node<T> * node<T>::right() const
{
    // return the right node
    return rightptr;
}


template <class T> void node<T>::right(node<T> * r)
{
    // set the right node
    rightptr = r;
}



//----------------------------------------------------------------------
//	class searchTree implementation
//----------------------------------------------------------------------

template <class T> searchTree<T>::searchTree()
{
    // initialize tree
    root = 0;
}



template <class T> searchTree<T>::searchTree(searchTree<T> & v)
{
    // initialize tree by adding all the elements from argument
    searchTreeIterator<T> itr(v);

    root = 0;

    for (itr.init(); !itr; itr++)
        add(itr());
}



template <class T> searchTree<T>::~searchTree()
{
    // deallocate tree
    if (root)
        root->release();
}



template <class T> void searchTree<T>::add(T val)
{
    // add value to binary search tree
    if (root)
    {
        node<T> * current = root;
        node<T> * child;

        while (current)
        {
            if (current->value < val)
            {
                // add to right subtree
                child = current->right();

                if (!child)
                {
                    current->right(new node<T>(val));
                    return;
                }
            }
            else
            {
                // add to left subtree
                child = current->left();

                if (!child)
                {
                    current->left(new node<T>(val));
                    return;
                }
            }

            current = child;
        }
    }
    else
        root = new node<T>(val);
}



template <class T> void searchTree<T>::deleteAllValues()
{
    // remove all values from tree
    if (root != 0)
    {
        root->release();
        delete root;
        root = 0;
    }
}



template <class T> int searchTree<T>::includes(T val) const
{
    // see if argument value occurs in tree
    if (root)
    {
        node<T> * current = root;

        while (current)
        {
            if (current->value == val)
                return  1;

            if (current->value < val)
                current = current->right();
            else
                current = current->left();
        }
    }

    // not found
    return 0;
}



template <class T> int searchTree<T>::isEmpty() const
{
    return root == 0;
}



template <class T> void searchTree<T>::remove(T val)
{
    // remove value from a binary search tree
    // no root, just quit
    if (!root)
        return;

    // deleting root
    if (root->value == val)
    {
        node<T> * newroot = removeTop(root);
        delete root;
        root = newroot;
        return;
    }

    // otherwise some other node
    node<T> * parent = root;

    while (parent != 0)
    {
        node<T> * child;

        if (parent->value < val)
        {
            // search right subtree
            child = parent->right();

            if (child && (child->value == val))
            {
                parent->right(removeTop(child));
                delete child;
                child = 0;
            }
        }
        else
        {
            // search left subtree
            child = parent->left();

            if (child && (child->value == val))
            {
                parent->left(removeTop(child));
                delete child;
                child = 0;
            }
        }

        parent = child;
    }
}



template <class T> node<T> * searchTree<T>::removeTop(node<T> * topNode)
{
    // remove topmost node from a binary search tree
    node<T> * left  = topNode->left();
    node<T> * right = topNode->right();

    // case 1, no left node
    if (left == 0)
        return right;

    // case 2, no right node
    if (right == 0)
        return left;

    // case 3, right node has no left node
    node<T> * n = right->left();

    if (n == 0)
    {
        right->left(left);
        return right;
    }

    // case 4, slide down left tree
    node<T> * parent = right;

    while (n->left() != 0)
    {
        parent = n;
        n = n->left();
    }

    // now parent point to n, n has no left child
    // disconnect and move to top
    parent->left(n->right());
    n->left(left);
    n->right(right);
    return n;
}



//----------------------------------------------------------------------
//	class searchTreeIterator implementation
//----------------------------------------------------------------------

template <class T> searchTreeIterator<T>::
    searchTreeIterator(searchTree<T> & t)
    : inorderTreeTraversal<T>(t.root), base(t)
{
    // no further initialization
}



template <class T> int searchTreeIterator<T>::init()
{
    // first set root for the iterator
    setRoot(base.root);

    // then do inorder iterator initialization
    return inorderTreeTraversal<T>::init();
}



//----------------------------------------------------------------------
//	class avlNode implementation
//----------------------------------------------------------------------

template <class T> avlNode<T>::avlNode(T value)
    : node<T>(value)
{
    balFac = 0;
}


template <class T> avlNode<T>::
	avlNode(T value, node<T> * left, node<T> * right)
		: node<T>(value, left, right)
{
	balFac = 0;
}

template <class T> void avlNode<T>::left(avlNode<T> * v)
{
    node<T>::left(v);
}



template <class T> avlNode<T> * avlNode<T>::left() const
{
    return (avlNode<T> *) node<T>::left();
}



template <class T> void avlNode<T>::right(avlNode<T> * v)
{
    node<T>::right(v);
}



template <class T> avlNode<T> * avlNode<T>::right() const
{
    return (avlNode<T> *) node<T>::right();
}



template <class T> avlNode<T> * avlNode<T>::add(T val)
{
    // add new element into balanced avl tree
    if (val < value)
    {
        // insert into left subtree
        if (left())
        {
            int oldbf = left()->balFac;
            left(left()->add(val));

            // check to see if tree grew
            if ((left()->balFac != oldbf) && left()->balFac)
                balFac--;
        }
        else
        {
            left(new avlNode<T>(val));

            // 0 becomes -1, 1 becomes 0
            balFac--;
        }
    }
    else
    {
        // insert into right subtree
        if (right())
        {
            int oldbf = right()->balFac;
            right(right()->add(val));

            // check to see if tree grew
            if ((right()->balFac != oldbf) && right()->balFac)
                balFac++;
        }
        else
        {
            right(new avlNode<T>(val));

            // 0 becomes 1, -1 becomes 0
            balFac++;
        }
    }

    // check if we are now out of balance, if so balance
    if ((balFac < -1) || (balFac > 1))
        return balance();

    return this;
}



template <class T> avlNode<T> * avlNode<T>::
    remove(T val, avlNode<T> * & junk)
{
    // remove indicated node, returning node in variable junk
    if (val == value)
    {
        // we're it
        junk = this;

        // if no right child, return left
	if (!left())
		return right();
        if (!right())
            return left();

        // else find and remove smallest left
        // child of the right child
        int oldbf = right()->balFac;
        avlNode<T> * newroot;
        right(right()->removeLeftmostDescendent(newroot));

        // connect new root
        newroot->left(left());
        newroot->right(right());
        newroot->balFac = balFac;
        return newroot->restoreRightBalance(oldbf);
    }
    else if (val < value)
    {
        // remove from left child
        if (!left())
            return this;    // no left child

        // do the deletion
        int oldbf = left()->balFac;
        left(left()->remove(val, junk));
        return restoreLeftBalance(oldbf);
    }
    else
    {
        // remove from right child
        if (!right())
            return this;

        // do the deletion
        int oldbf = right()->balFac;
        right(right()->remove(val, junk));
        return restoreRightBalance(oldbf);
    }
}



template <class T> node<T> * avlNode<T>::copy() const
{
    // return copy of tree rooted at node
    node<T> * newLeft;
    node<T> * newRight;

    // duplicate left child
    if (leftptr != 0)
	newLeft = leftptr->copy();
    else
        newLeft = 0;

    // duplicate right child
    if (rightptr != 0)
	newRight = rightptr->copy();
    else
	newRight = 0;

    // duplicate node, check that allocation worked
    avlNode<T> * newptr = new avlNode<T>(value, newLeft, newRight);
    assert(newptr != 0);
    newptr->balFac = balFac;

    // return new node
    return newptr;
}



template <class T> avlNode<T> * avlNode<T>::singleRotateLeft()
{
    // perform a single left rotation of the current node
    avlNode<T> * nodeA = this;
    avlNode<T> * nodeB = nodeA->right();

    // make reconnections
    nodeA->right(nodeB->left());
    nodeB->left(nodeA);

    // now update the balance factors
    int Abf = nodeA->balFac;
    int Bbf = nodeB->balFac;

    if (Bbf <= 0)
    {
        if (Abf >= 1)
            nodeB->balFac = Bbf - 1;
        else
            nodeB->balFac = Abf + Bbf - 2;

        nodeA->balFac = Abf - 1;
    }
    else
    {
        if (Abf <= Bbf)
            nodeB->balFac = Abf - 2;
        else
            nodeB->balFac = Bbf - 1;

        nodeA->balFac = (Abf - Bbf) - 1;
    }

    return nodeB;
}



template <class T> avlNode<T> * avlNode<T>::singleRotateRight()
{
    // make a single right rotation of current node
    avlNode<T> * nodeA = this;
    avlNode<T> * nodeB = nodeA->left();

    // make reconnections
    nodeA->left(nodeB->right());
    nodeB->right(nodeA);

    // now update the balance factors
    int Abf = nodeA->balFac;
    int Bbf = nodeB->balFac;

    if (Bbf <= 0)
    {
        if (Bbf > Abf)
            nodeB->balFac = Bbf + 1;
        else
            nodeB->balFac = Abf + 2;

        nodeA->balFac = 1 + Abf - Bbf;
    }
    else
    {
        if (Abf <= -1)
            nodeB->balFac = Bbf + 1;
        else
            nodeB->balFac = Abf + Bbf + 2;

        nodeA->balFac = 1 + Abf;
    }

    return nodeB;
}



template <class T> avlNode<T> * avlNode<T>::restoreLeftBalance(int oldbf)
{
    avlNode<T> * leftchild = left();

    // fix up our balance factors
    if (!leftchild)
        balFac++;
    else if ((leftchild->balFac != oldbf) && (leftchild->balFac == 0))
        balFac++;

    // rebalance if necessary
    if (balFac > 1)
        return balance();

    return this;
}



template <class T> avlNode<T> * avlNode<T>::restoreRightBalance(int oldbf)
{
    avlNode<T> * rightchild = right();

    // fix up our balance factors
    if (!rightchild)
        balFac++;
    else if ((rightchild->balFac != oldbf) && (rightchild->balFac == 0))
        balFac++;

    // rebalance if necessary
    if (balFac > 1)
        return balance();

    return this;
}



template <class T> avlNode<T> * avlNode<T>::balance()
{
    // balance tree rooted at node
    // using single or double rotations as appropriate
    if (balFac < 0)
    {
        if (left()->balFac <= 0)
        {
            // perform single rotation
            return singleRotateRight();
        }
        else
        {
            // perform double rotation
            left(left()->singleRotateLeft());
            return singleRotateRight();
        }
    }
    else
    {
        if (right()->balFac >= 0)
            return singleRotateLeft();
        else
        {
            // perform double rotation
            right(right()->singleRotateRight());
            return singleRotateLeft();
        }
    }
}



template <class T> avlNode<T> * avlNode<T>::removeLeftmostDescendent
    (avlNode<T> * & childptr)
{
    // find and remove the leftmost descendent of a node
    // first see if we are the left child
    avlNode<T> * leftchild = left();

    if (! leftchild)
    {
        // we are
        childptr = this;
        return right();    // remove self
    }

    // else save old bal factor of left child
    int oldbf = leftchild->balFac;

    // do the deletion
    left(leftchild->removeLeftmostDescendent(childptr));

    // fix up our balance factors
    return restoreLeftBalance(oldbf);
}



//----------------------------------------------------------------------
//	class avlTree implementation
//----------------------------------------------------------------------

template <class T> void avlTree<T>::add(T val)
{
    // add new value into balanced AVL tree
    if (root)
        root = rootptr()->add(val);
    else
        root = new avlNode<T>(val);
}



template <class T> void avlTree<T>::remove(T val)
{
    // remove an element from an AVL Tree
    avlNode<T> * eliminatedNode = 0;

    if (root)
        root = rootptr()->remove(val, eliminatedNode);
    if (eliminatedNode)
        delete eliminatedNode;
}



template <class T> avlNode<T> * avlTree<T>::rootptr()
{
    return (avlNode<T> *) root;
}



//----------------------------------------------------------------------
//	class postorderTreeTraversal implementation
//----------------------------------------------------------------------

template <class T> postorderTreeTraversal<T>::
    postorderTreeTraversal(node<T> * r)
    : root(r)
{
    // no further initialization
}

template <class T> postorderTreeTraversal<T>::
    postorderTreeTraversal(const postorderTreeTraversal<T> & x)
	: root(x.root)
{
	// no further initialization
}

template <class T> int postorderTreeTraversal<T>::init()
{
    // clear out the stack
    itrstack.deleteAllValues();

    // then initialize it
    stackChildren(root);
    return !itrstack.isEmpty();
}



template <class T> int postorderTreeTraversal<T>::operator !()
{
    // we are done when stack is empty
    return !itrstack.isEmpty();
}



template <class T> T postorderTreeTraversal<T>::operator()()
{
    // return value of current node
    node<T> * n = itrstack.top();
    return n->value;
}



template <class T> void postorderTreeTraversal<T>::operator=(T val)
{
    // change the current value
    node<T> * n = itrstack.top();
    n->value = val;
}



template <class T> int postorderTreeTraversal<T>::operator ++()
{
    // move to the next item in sequence
    // pop current node from stack
    itrstack.pop();

    // return false if stack is empty, and hence there are no more items
    return !itrstack.isEmpty();
}



template <class T> void postorderTreeTraversal<T>::
    setRoot(node<T> * newRoot)
{
    // set new root
    root = newRoot;
}



template <class T> void postorderTreeTraversal<T>::
    stackChildren(node<T> * n)
{
    // stack all the children of the current node
    itrstack.push(n);
    node<T> * next = n->right();

    if (next)
        stackChildren(next);

    next = n->left();

    if (next)
        stackChildren(next);
}



//----------------------------------------------------------------------
//	class preorderTreeTraversal implementation
//----------------------------------------------------------------------

template <class T> preorderTreeTraversal<T>::
    preorderTreeTraversal(node<T> * r)
    : root(r)
{
    // no further initialization
}

template <class T> preorderTreeTraversal<T>::
    preorderTreeTraversal(const preorderTreeTraversal<T> & x)
	: root(x.root)
{
	// no further initialization
}

template <class T> int preorderTreeTraversal<T>::init()
{
    // initialize a preorder traversal of a tree
    // first initialize the stack
    itrstack.deleteAllValues();

    // first time out, just push the root
    if (root != 0)
        itrstack.push(root);

    return !itrstack.isEmpty();
}



template <class T> int preorderTreeTraversal<T>::operator !()
{
    // we are done when stack is empty
    return !itrstack.isEmpty();
}



template <class T> T preorderTreeTraversal<T>::operator()()
{
    // return value of current node
    node<T> * n = itrstack.top();
    return n->value;
}



template <class T> void preorderTreeTraversal<T>::operator=(T val)
{
    // change the current value
    node<T> * n = itrstack.top();
    n->value = val;
}



template <class T> int preorderTreeTraversal<T>::operator ++()
{
    // inv - for each node on stack except top
    // left children are being investigated
    // for all including top no right children have been visited
    node<T> * current = itrstack.top();
    node<T> * next = current->left();

    if (next)
    {
        itrstack.push(next);
        return 1;
    }

    // no more left nodes,
    // find unexplored right child
    while (! itrstack.isEmpty())
    {
        current = itrstack.pop();
        next = current->right();

        if (next)
        {
            // note parent is not on stack,
            // preserving invariant
            itrstack.push(next);
            return 1;
        }
    }

    return 0;
}



template <class T> void preorderTreeTraversal<T>::
    setRoot(node<T> * newRoot)
{
    // set new root
    root = newRoot;
}



//----------------------------------------------------------------------
//	class inorderTreeTraversal implementation
//----------------------------------------------------------------------

template <class T> inorderTreeTraversal<T>::
    inorderTreeTraversal(node<T> * initialRoot)
    : itrstack(32)
{
    root = initialRoot;
    itrstack.deleteAllValues();
}

template <class T> inorderTreeTraversal<T>::
	inorderTreeTraversal(const inorderTreeTraversal<T> & x)
	: itrstack(32), root(x.root)
{

}

template <class T> int inorderTreeTraversal<T>::init()
{
    // initialize inorder tree traversal
    // clear out the stack
    itrstack.deleteAllValues();

    // then reinitialize it
    slideLeft(root);
    return !itrstack.isEmpty();
}



template <class T> int inorderTreeTraversal<T>::operator !()
{
    // we are done when stack is empty
    return !itrstack.isEmpty();
}



template <class T> T inorderTreeTraversal<T>::operator()()
{
    // return value of current node
    node<T> * n = itrstack.top();
    return n->value;
}



template <class T> void inorderTreeTraversal<T>::operator=(T val)
{
    // change the current value
    node<T> * n = itrstack.top();
    n->value = val;
}



template <class T> int inorderTreeTraversal<T>::operator ++()
{
    // inv - for each node on stack, left children
    // have been explored, right children have not
    if (! itrstack.isEmpty())
    {
        node<T> * n    = itrstack.pop();
        node<T> * next = n->right();

        if (next)
            slideLeft(next);
    }

    // if stack isn't empty we have nodes
    return !itrstack.isEmpty();
}



template <class T> void inorderTreeTraversal<T>::
    setRoot(node<T> * newRoot)
{
    // set new root
    root = newRoot;
}



template <class T> void inorderTreeTraversal<T>::
    slideLeft(node<T> * current)
{
    // slide left from the current node
    while (current)
    {
        itrstack.push(current);
        current = current->left();
    }
}



//----------------------------------------------------------------------
//	class levelorderTreeTraversal implementation
//----------------------------------------------------------------------

template <class T> levelorderTreeTraversal<T>::
    levelorderTreeTraversal(node<T> * r)
    : root(r)
{
    // no further initialization
}


template <class T> levelorderTreeTraversal<T>::
	levelorderTreeTraversal(const levelorderTreeTraversal<T> & x)
		: root(x.root), itrqueue(x.itrqueue)
{
	// no further initialization
}

template <class T> int levelorderTreeTraversal<T>::init()
{
    // initialize a preorder traversal of a tree
    // first initialize the queue
    itrqueue.deleteAllValues();

    // first time out, just enqueue the root
    if (root != 0)
        itrqueue.enqueue(root);

    return !itrqueue.isEmpty();
}

template <class T> int levelorderTreeTraversal<T>::operator !()
{
    // we are done when queue is empty
    return !itrqueue.isEmpty();
}



template <class T> T levelorderTreeTraversal<T>::operator()()
{
    // return value of current node
    node<T> * n = itrqueue.front();
    return n->value;
}



template <class T> void levelorderTreeTraversal<T>::operator=(T val)
{
    // change the current value
    node<T> * n = itrqueue.front();
    n->value = val;
}



template <class T> int levelorderTreeTraversal<T>::operator ++()
{
    // queue children of current node
    if (!itrqueue.isEmpty())
    {
        node<T> * n = itrqueue.dequeue();
        node<T> * next;
        next = n->left();

        if (next)
            itrqueue.enqueue(next);

        next = n->right();

        if (next)
            itrqueue.enqueue(next);
    }

    return !itrqueue.isEmpty();
}



template <class T> void levelorderTreeTraversal<T>::
    setRoot(node<T> * newRoot)
{
    // set new root
    root = newRoot;
}


//----------------------------------------------------------------------
//	miscellaneous template functions
//----------------------------------------------------------------------

// preorder processing of tree rooted at current

template <class T> void preorder(node<T> * current)
{
    // visit node, left child, right child
    if (current)
    {
        // process current node
        process(current->value);

        // then visit children
        preorder(current->left());
        preorder(current->right());
    }
}



// inorder processing of tree rooted at current

template <class T> void inorder(node<T> * current)
{
    // visit left child, node, right child
    if (current)
    {
        inorder(current->left());
        process(current->value);
        inorder(current->right());
    }
}



// postorder processing of tree rooted at current

template <class T> void postorder(node<T> * current)
{
    // visit left child, right child, node
    if (current)
    {
        postorder(current->left());
        postorder(current->right());
        process(current->value);
    }
}

//
//	g++ and cfront treat these differently
//

# ifdef __GNUG__

# include "tree.c"

# endif

# ifndef __GNUG__

template <class T> void treeSort(vector<T> & v);

# endif

#endif

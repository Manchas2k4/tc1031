#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 3;

void f(int g[SIZE][SIZE]) {
    int h[SIZE][SIZE];

    h[0][0] = (g[0][1] + g[1][0]) % 2;
	h[0][1] = (g[0][0] + g[1][1] + g[0][2]) % 2;
	h[0][2] = (g[0][1] + g[1][2]) % 2;

	h[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	h[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	h[1][2] = (g[1][1] + g[0][2] + g[2][2]) % 2;

	h[2][0] = (g[2][1] + g[1][0]) % 2;
	h[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	h[2][2] = (g[2][1] + g[1][2]) % 2;

    for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			g[i][j] = h[i][j];
		}
	}
}

bool isAllZeros(const int g[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (g[i][j] > 0) {
                return false;
            }
		}
	}
    return true;
}

int main(int argc, char* argv[]) {
    int cases;
    int g[SIZE][SIZE];
    string line;

    cin >> cases;
    for (int t = 0; t < cases; t++) {

        int i = 0;
         while (i < SIZE) {
            getline(cin, line);
            
            line.erase(line.find_last_not_of("\r\n") + 1);

            if (line.length() == 0) {
                continue;
            }

            for (int j = 0; j < SIZE; j++) {
                g[i][j] = line[j] - '0';
            }
            i++;
        }

        int answer = -1;
        while (true) {
            if (isAllZeros(g)) {
                break;
            }

            f(g);
            answer++;
        }
        cout << answer << "\n";
    }
    return 0;
}
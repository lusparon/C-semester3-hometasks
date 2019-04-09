#include <iostream>
#include <locale>

using namespace std;

bool isSimple(long long A) {
	int flag = 1;
	for (long long i = 2;i<A;i++) {
		if (A%i == 0) {
			flag = 0;
			return false;
		}
	}
	if (flag = 1) return true;
}

int main() {
	std::locale::global(std::locale(""));
	long long A = 600851475143, result;

	for (long long i = 2;i<A;i++) {
		if ((A%i == 0) && (isSimple(A)))
			result = i;
	}

	cout << "—амый большой делитель числа 600851475143,€вл€ющийс€ простым =  " << result << endl;

	system("pause");
	return 0;
}
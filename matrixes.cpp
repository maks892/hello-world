#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <initializer_list>

using namespace std;

class Macierz2D {
private:
	float** m_dane;
	const int rozmiar = 3;

public:
	Macierz2D();
	Macierz2D(float);
	Macierz2D(float**);
	Macierz2D(initializer_list<float>);
	~Macierz2D();

	Macierz2D& operator=(const Macierz2D&);
	Macierz2D& operator+(Macierz2D&);
	Macierz2D& operator+=(Macierz2D&);
	Macierz2D& operator-(Macierz2D&);
	Macierz2D& operator-=(Macierz2D&);
	Macierz2D& operator*(Macierz2D&);
	Macierz2D& operator*=(Macierz2D&);
	Macierz2D& operator*(float);
	Macierz2D& operator*=(float);
	Macierz2D& operator++();
	Macierz2D operator++(int);
	Macierz2D& operator--();
	Macierz2D operator--(int);
	friend ostream& operator<<(ostream&, const Macierz2D&);
	friend istream& operator>>(istream&, const Macierz2D&);
	float operator()(int, int);
	void operator()(int, int, float);
	bool operator==(Macierz2D&);
	bool operator!=(Macierz2D&);
	bool operator<(Macierz2D&);
	bool operator<=(Macierz2D&);
	bool operator>(Macierz2D&);
	bool operator>=(Macierz2D&);

	void transpose();
	void make_unitary();
	float count_sum();
};

//Constructors
Macierz2D::Macierz2D() {
	m_dane = new float* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		*(m_dane + i) = new float[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			m_dane[i][j] = 0;
		}
	}
}

Macierz2D::Macierz2D(initializer_list<float>list){
	m_dane = new float* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		*(m_dane + i) = new float[rozmiar];
	}
	if (list.size() == 9) {
		initializer_list<float>::iterator iter = list.begin();
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				m_dane[i][j] = *iter;
				iter++;
			}
		}
	}
}

Macierz2D::Macierz2D(float el) {
	m_dane = new float* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		*(m_dane + i) = new float[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			m_dane[i][j] = el;
		}
	}
}
Macierz2D::Macierz2D(float** tab) {
	m_dane = new float* [rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		*(m_dane + i) = new float[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			m_dane[i][j] = tab[i][j];
		}
	}
}

Macierz2D::~Macierz2D() {
	for (int i = 0; i < rozmiar; i++) { delete m_dane[i]; }
	delete m_dane;
}

//operators
Macierz2D& Macierz2D::operator=(const Macierz2D& matrix) {
	 for(int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			m_dane[i][j] = matrix.m_dane[i][j];
		}
	}
	 return *this;
}

Macierz2D& Macierz2D::operator+(Macierz2D& matrix) {
	Macierz2D* sum = new Macierz2D();
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			sum->m_dane[i][j] = this->m_dane[i][j] + matrix.m_dane[i][j];
		}
	}
	return *sum;
}

Macierz2D& Macierz2D::operator+=(Macierz2D& matrix) {
	*this = *this + matrix;
	return *this;
}

Macierz2D& Macierz2D::operator++() {
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			this->m_dane[i][j]++;
		}
	}
	return *this;
}

Macierz2D Macierz2D::operator++(int) {
	Macierz2D* rez = new Macierz2D();
	*rez = *this;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			this->m_dane[i][j]++;
		}
	}
	return *rez;
}

Macierz2D& Macierz2D::operator-(Macierz2D& matrix) {
	Macierz2D* subtract = new Macierz2D();
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			subtract->m_dane[i][j] = this->m_dane[i][j] - matrix.m_dane[i][j];
		}
	}
	return *subtract;
}

Macierz2D& Macierz2D::operator-=(Macierz2D& matrix) {
	*this = *this - matrix;
	return *this;
}

Macierz2D& Macierz2D::operator--() {
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			this->m_dane[i][j]--;
		}
	}
	return *this;
}

Macierz2D Macierz2D::operator--(int) {
	Macierz2D* rez = new Macierz2D();
	*rez = *this;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			this->m_dane[i][j]--;
		}
	}
	return *rez;
}

Macierz2D& Macierz2D::operator*( Macierz2D& matrix) {
	Macierz2D* product = new Macierz2D();
	for (int k = 0; k < rozmiar; k++) {
		for (int t = 0; t < rozmiar; t++) {
			for (int i = 0; i < rozmiar; i++) {
				product->m_dane[k][t] += this->m_dane[k][i] * matrix.m_dane[t][i];
			}
		}
	}
	return *product;
}

Macierz2D& Macierz2D::operator*=( Macierz2D& matrix) {
	*this = *this * matrix;
	return *this;
}

Macierz2D& Macierz2D::operator*(float number) {
	Macierz2D* product = new Macierz2D();
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			product->m_dane[i][j] = this->m_dane[i][j] * number;
		}
	}
	return *product;
}



ostream& operator<<(ostream& source, const Macierz2D& matrix) {
	string buf;
	for (int i = 0; i < matrix.rozmiar; i++) { printf("  -----"); }
	source << "\n";
	for (int i = 0; i < matrix.rozmiar; i++) {
		source << "|";
		for (int j = 0; j < matrix.rozmiar; j++) {
			buf = to_string(matrix.m_dane[i][j]);

			if (buf.length() > 5) {
				if ((buf[5] - '0') >= 5) {
					int t = 4;
					while (t >= 0) {
						if (buf[t] == '9') {
							buf[t] = '0';
						}
						else if (buf[t] == '.') { t--; continue; }
						else {
							buf[t] = (buf[t] - '0' + 1) + '0';
							break;
						}
						t--;
					}
				}
			}
			source << " ";
			for (int k = 0; k < 5 && k < buf.length(); k++) { 
				if (buf[k] != '.' || k < 4) { source << buf[k]; }
				else { source << " "; }
			}
			if (buf.length() < 5) { for (int k = buf.length(); k < 5; k++) { source << '0'; } }
			source << " ";
		}
		source << "|\n";
	}
	for (int i = 0; i < matrix.rozmiar; i++) { printf("  -----"); }
	source << "\n";
	return source;
}

istream& operator>>(istream& source, const Macierz2D& matrix) {
	for (int i = 0; i < matrix.rozmiar; i++) {
		for (int j = 0; j < matrix.rozmiar; j++) {
			source >> matrix.m_dane[i][j];
		}
	}
	return source;
}

float Macierz2D::operator()(int raw, int column) {
	return this->m_dane[raw][column];
}

void Macierz2D::operator()(int raw, int column, float number) {
	this->m_dane[raw][column] = number;
}

bool Macierz2D::operator==(Macierz2D& matrix) {
	return count_sum() == matrix.count_sum();
}

bool Macierz2D::operator!=(Macierz2D& matrix) {
	return count_sum() != matrix.count_sum();
}

bool Macierz2D::operator<(Macierz2D& matrix) {
	return count_sum() < matrix.count_sum();
}

bool Macierz2D::operator<=(Macierz2D& matrix) {
	return count_sum() <= matrix.count_sum();
}

bool Macierz2D::operator>(Macierz2D& matrix) {
	return count_sum() > matrix.count_sum();
}

bool Macierz2D::operator>=(Macierz2D& matrix) {
	return count_sum() >= matrix.count_sum();
}

//other methods
void Macierz2D::transpose() {
	Macierz2D buf;
	buf = *this;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			this->m_dane[j][i] = buf.m_dane[i][j];
		}
	}
}

void Macierz2D::make_unitary() {
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (i == j) { this->m_dane[i][j] = 1; }
			else { this->m_dane[i][j] = 0; }
		}
	}
}

float Macierz2D::count_sum() {
	float sum = 0;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			sum += m_dane[i][j];
		}
	}
	return sum;
}

int main() {

	Macierz2D m3;
	Macierz2D m1 = {1.12, 1.6256, 1.009, 222, 1.89, 55.09, 12.657, 19.098, 111.1};
	Macierz2D m2 = {9.6, 0.01, 1.76, 1.097, 2.4679879, 3.8888, 3.12, 6.666, 109.8765};
	cout << "m1 matrix:\n" << m1 << endl;
	cout << "m2 matrix:\n" << m2 << endl;
	cout << "m1 transposed:\n";
	m3 = m1;
	m3.transpose();
	cout << m3;
	cout << "unitary matrix:\n";
	m3.make_unitary();
	cout << m3;
	
	cout << "m1*m2 = \n";
	cout << m1 * m2 << endl;
	cout << "m1+m2 = \n";
	cout << m1+m2 << endl;
	cout << "m1-m2 = \n";
	cout << m1 - m2 << endl;
	cout << "m2*12 = \n";
	cout << m2*12 << endl;
	m3 = m1;
	cout << "++m1 = \n";
	cout << ++m3 << endl;
	m3 = m1;
	cout << "m1++ = \n";
	cout << m3++ << endl;
	m3 = m1;
	cout << "--m1 = \n";
	cout << --m3 << endl;
	m3 = m1;
	cout << "m1-- = \n";
	cout << m3-- << endl;
	cout << "m1[0][1] = " << m1(0, 1) << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m1(i, j, i * j);
		}
	}
	cout << m1 << endl;
	
	Macierz2D m4 = { 1,2,3,4,5,6,7,8,9 };
	Macierz2D arr[3];
	arr[0] = m2;
	arr[1] = m3;
	arr[2] = m1;
	

	sort(arr, arr+2);

	for (int i = 0; i < 3; i++) { cout << "arr[" << i << "] = " << arr[i] << endl; }
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void chinh_sua_ten(string& Ho_va_ten) {
	while (Ho_va_ten[0] == ' ') {
		Ho_va_ten.erase(0, 1);

	}
	for (int i = 0; i < Ho_va_ten.length() - 1; i++) {
		if (Ho_va_ten[i] == ' ' && Ho_va_ten[i + 1] == ' ') {
			Ho_va_ten.erase(i, 1);
			i -= 1;
		}
	}
	Ho_va_ten[0] = toupper(Ho_va_ten[0]);
	for (int i = 0; i < Ho_va_ten.length() - 1; i++) {
		if (Ho_va_ten[i] == ' ') {
			Ho_va_ten[i + 1] = toupper(Ho_va_ten[i + 1]);

		}
		else {
			Ho_va_ten[i + 1] = tolower(Ho_va_ten[i + 1]);
		}
	}
}

struct Birthday {
	int days;
	int months;
	int years;

};

struct Hoc_sinh {
	string name;
	int MSSV;
	string sdt;
	Birthday DOB;
	friend istream& operator>> (istream& is, Hoc_sinh& hoc_sinh) {
		system("cls");
		cout << " Nhap ten: ";
		is.ignore();
		getline(is, hoc_sinh.name);
		chinh_sua_ten(hoc_sinh.name);
		cout << " MSSV: ";
		cin >> hoc_sinh.MSSV;
		cout << " SDT: ";
		is.ignore();
		getline(is, hoc_sinh.sdt);
		cout << "Nhap ngay thang nam sinh\n";
		cout << "Ngay: "; cin >> hoc_sinh.DOB.days;
		cout << "Thang: "; cin >> hoc_sinh.DOB.months;
		cout << "Nam: "; cin >> hoc_sinh.DOB.years;
		return is;
	}
	friend ostream& operator<< (ostream& os, Hoc_sinh hoc_sinh) {
		os << "Ten: " << hoc_sinh.name << endl;
		os << "MSSV: " << hoc_sinh.MSSV << endl;
		os << "SDT: " << hoc_sinh.sdt << endl;
		os << "Ngay thang nam sinh: " << hoc_sinh.DOB.days << "/" << hoc_sinh.DOB.months << "/" << hoc_sinh.DOB.years << endl;
		return os;
	}

};
void In_ra_ten_hoi(Hoc_sinh* hoc_sinh, int size) {
	for (int i = 0; i < size; i++) {
		cout <<i+1<<" "<< hoc_sinh[i].name << endl;
	}
}

void In_ra_DS_sinh_vien(Hoc_sinh*& hoc_sinh, int size) {
	if (!size) {
		cout << endl;
		cout << " chua co hoc sinh nao\n	";
	}
	else {
		system("cls");
		for (int i = 0; i < size; i++) {
			cout << "================================\n";
			cout << hoc_sinh[i];
		}
	}
	cout << "================================\n";

}

void Them_hoc_sinh(Hoc_sinh*& hoc_sinh, int& size) {
	Hoc_sinh hoc_sinh_moi;
	cout << "Nhap thong tin hoc sinh moi" << endl;
	cin >> hoc_sinh_moi;

	int new_size = size + 1;

	Hoc_sinh* hoc_sinh_tmp = new Hoc_sinh[new_size ];

	for (int i = 0; i < size; i++) {
		hoc_sinh_tmp[i] = hoc_sinh[i];

	}

	hoc_sinh_tmp[new_size - 1] = hoc_sinh_moi;
	delete[] hoc_sinh;
	hoc_sinh = hoc_sinh_tmp;
	size = size + 1;
	cout << "Them thanh cong ..." << endl;

}

void Xoa_hoc_sinh(Hoc_sinh*& hoc_sinh, int& size) {
	int n;
	In_ra_ten_hoi(hoc_sinh, size);
	cout << " Nhap vi tri phan tu can xoa: ";
	cin >> n;
	for (int i = n - 1; i < size - 1; i++) {
		hoc_sinh[i] = hoc_sinh[i + 1];

	}
	size = size - 1;
	cout << " Xoa thanh cong ..." << endl;
}

void sua_thong_tin(Hoc_sinh*& hoc_sinh, int size) {
	int n;
	In_ra_ten_hoi(hoc_sinh, size);
	cout << " Nhap vi tri ma ban muon sua thong tin: ";
	cin >> n;
	int new_n = n - 1;
	Hoc_sinh hoc_sinh_tmp;
	cin >> hoc_sinh_tmp;
	hoc_sinh[new_n] = hoc_sinh_tmp;
	cout << "Sua thanh cong ...\n";
}

int Tim_kiem(Hoc_sinh*& hoc_sinh, string ten_can_tim, int size) {
	for (int i = 0; i < size; i++) {
		int n = ten_can_tim.compare(hoc_sinh[i].name);
		if (n == 0) {
			return i + 1;
		}
	}
	return 0;

}

void Sap_xep(Hoc_sinh*& hoc_sinh, int size) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (hoc_sinh[j].MSSV > hoc_sinh[j + 1].MSSV) {
				swap(hoc_sinh[j], hoc_sinh[j + 1]);
			}
		}
	}
	cout << " sap xep thanh cong ...";
}







struct Hoc_phan {
	string Ma_mon_hoc;
	float Hs_giua_ki, Hs_cuoi_ki;
	friend istream& operator>> (istream& is, Hoc_phan& mon_hoc) {
		system("cls");
		cout << "Nhap ma mon hoc: ";
		is.ignore();
		getline(is, mon_hoc.Ma_mon_hoc);
		cout << "He giua ki: "; cin >> mon_hoc.Hs_giua_ki;
		cout << "He cuoi ki: "; cin >> mon_hoc.Hs_cuoi_ki;
		return is;
	}

};

void Them_hoc_phan(Hoc_phan*& mon_hoc, int& number) {
	Hoc_phan mon_hoc_moi;
	cout << "Ma mon hoc can them vao" << endl;
	cin >> mon_hoc_moi;
	int new_number = number + 1;
	Hoc_phan* mon_hoc_tmp = new Hoc_phan[new_number];
	for (int i = 0; i < number; i++) {
		mon_hoc_tmp[i] = mon_hoc[i];
	}
	mon_hoc_tmp[new_number - 1] = mon_hoc_moi;
	delete[] mon_hoc;
	mon_hoc = mon_hoc_tmp;
	number += 1;
	cout << "Hoc Phan moi da duoc them vao he thong...\n";
}


void Xoa_hoc_phan(Hoc_phan*& mon_hoc, int& number) {
	int n;
	cout << " Nhap vi tri can xoa: "; cin >> n;
	n = n + 1;
	for (int i = n + 1; i < number; i++) {
		mon_hoc[i] = mon_hoc[i + 1];
	}
	number -= 1;
}

void In_ra_mon_hoc(Hoc_phan*& mon_hoc, int number) {
	if (!number) {
		cout << endl;
		cout << "chua co mon hoc nao\n";
	}
	else {
		for (int i = 0; i < number; i++) {
			cout << mon_hoc[i].Ma_mon_hoc;
		}
	}

}

class Diem_so {
public:
	float GK, CK;

	Diem_so() {
		GK = 0;
		CK = 0;
	}
	void diem_tong_ket(float x, float y) {
		float m = GK * x + CK * y;
		cout << "Tong ket: " << m; cout << " Xep Loai: ";
		if (m < 4) { cout << "F"; }
		else if (m < 5) { cout << "D"; }
		else if (m < 5.5) { cout << "D+"; }
		else if (m < 6) { cout << "C"; }
		else if (m < 7) { cout << "C+"; }
		else if (m < 8) { cout << "B"; }
		else if (m < 8.5) { cout << "B+"; }
		else if (m < 9.5) { cout << "A"; }
		else { cout << "A+"; }
	}
	float Quy_doi_thang(float x, float y) {
		float m = GK * x + CK * y;
		if (m < 4) { return 0; }
		else if (m < 5) { return 1; }
		else if (m < 5.5) { return 1.5; }
		else if (m < 6) { return 2; }
		else if (m < 7) { return 2.5; }
		else if (m < 8) { return  3; }
		else if (m < 8.5) { return 3.5; }
		else { return 4; }
	}
};

int Choose() {
	int choice;
	system("cls");
	cout << "===============Bang Yeu Cau================" << endl;
	cout << "1. Danh sach Sinh Vien" << endl;
	cout << "2. Them Sinh Vien" << endl;
	cout << "3. Xoa Sinh Vien" << endl;
	cout << "4. Sua thong tin Sinh Vien" << endl;
	cout << "5. Tim kiem thong tin Sinh Vien" << endl;
	cout << "6. Sap xep theo thu tu tang dan cua MSSV" << endl;
	cout << "7. Tao hoc phan cho sinh vien" << endl;
	cout << "8. Xoa hoc phan cua sinh vien" << endl;
	cout << "10.Luu danh sach sinh vien ra file text" << endl;
	cout << "11.Nhap diem cho sinh vien" << endl;
	cout << "12.Xem diem sinh vien " << endl;
	cout << "13.Xuat file diem cua sinh vien" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon cua ban\n";
	cin >> choice;
	return choice;
}
int main() {
	fstream fs;
	fs.open("Danh_sach_sinh_vien.txt", ios::out);
	int size = 0, number = 0;
	int h = size, g = number;
	Hoc_phan* mon_hoc = new Hoc_phan[number];
	Hoc_sinh* hoc_sinh = new Hoc_sinh[size];

	Diem_so** diem = new Diem_so * [size];
	for (int i = 0; i < size; i++) {
		diem[i] = new Diem_so[number];
	}
	while (true) {
		int n = Choose();
		switch (n) {

		case 1:
			// xem danh sach
			In_ra_DS_sinh_vien(hoc_sinh, size);
			break;
		case 2:
			// them hoc sinh
			Them_hoc_sinh(hoc_sinh, size);
			break;
		case 3:
			// xoa hoc sinh
			Xoa_hoc_sinh(hoc_sinh, size);
			break;
		case 4:
			//sua thong tin
			sua_thong_tin(hoc_sinh, size);
			break;
		case 5:
			if (n == 5) {
				string Ten_can_tim;
				cin.ignore();
				cout << "Nhap ten ban can tim: ";
				getline(cin, Ten_can_tim);
				chinh_sua_ten(Ten_can_tim);
				int z = Tim_kiem(hoc_sinh, Ten_can_tim, size);
				if (z != 0) {
					cout << hoc_sinh[z - 1];
				}
				else { cout << " ko tim thay \n"; }
				break;
			}
		case 6:
			Sap_xep(hoc_sinh, size);
			break;
		case 7:
			Them_hoc_phan(mon_hoc, number);
			break;

		case 8:
			Xoa_hoc_phan(mon_hoc, number);
			break;
		case 9:
			In_ra_mon_hoc(mon_hoc, number);
			break;
		case 10:
			for (int i = 0; i < size; i++) {
				fs << "Ho va Ten: " << hoc_sinh[i].name << endl;
				fs << "Ma so sinh vien: " << hoc_sinh[i].MSSV << endl;
				fs << "SDT: " << hoc_sinh[i].sdt << endl;
				fs << "Ngay thang nam sinh: " << hoc_sinh[i].DOB.days << "/" << hoc_sinh[i].DOB.months << "/" << hoc_sinh[i].DOB.years << endl;
			}
			cout << "DONE.......\n";
			break;
		case 11:
			if (n == 11) {
				Diem_so** a = new Diem_so * [size];
				for (int i = 0; i < size; i++) {
					a[i] = new Diem_so[number];
				}
				for (int i = 0; i < g; i++) {
					delete[]diem[i];
				}
				delete[]diem;
				diem = a;
				cout << "Bang diem da duoc lap...." << endl;
			}
			h = size;
			g = number;
			for (int i = 0; i < size; i++) {
				system("cls");
				cout << hoc_sinh[i].name << endl;
				for (int j = 0; j < number; j++) {
					cout << mon_hoc[j].Ma_mon_hoc << endl;
					cout << "Diem giua ki: "; cin >> diem[i][j].GK;
					cout << "Diem cuoi ki: "; cin >> diem[i][j].CK;
					cout << "--------------------------------------" << endl;
				}
			}
			break;
		case 12:
			if (g != 0 && h != 0) {
				system("cls");
				for (int j = 0; j < size; j++) {
					float GPA = 0;
					cout << hoc_sinh[j].name << endl;
					for (int i = 0; i < number; i++) {
						cout << mon_hoc[i].Ma_mon_hoc << " Diem Qua Trinh: " << diem[j][i].GK << "(GK)  Diem cuoi ki: " << diem[j][i].CK << "(CK)   ";
						diem[j][i].diem_tong_ket(mon_hoc[i].Hs_giua_ki, mon_hoc[i].Hs_cuoi_ki);
						GPA = GPA + diem[j][i].Quy_doi_thang(mon_hoc[i].Hs_giua_ki, mon_hoc[i].Hs_cuoi_ki);
						cout << endl;
					}
					cout << "GPA: " << (float)GPA / number << endl;
					cout << "--------------------------------------\n";
				}
			}
			else { cout << "Ban chua nhap diem cho sinh vien\n"; }
			break;
		case 13:
			system("cls");
			if (n == 13) {
				for (int i = 0; i < size; i++) {
					cout << i + 1 << "." << hoc_sinh[i].name << endl;
				}
				cout << "Xuat file hoc sinh so may: " << endl;
				int x;
				cin >> x;
				x = x--;
				fstream hs;
				hs.open(hoc_sinh[x].name.append(".txt"), ios::out);
				hs << "Hoc sinh: " << hoc_sinh[x].name << endl;
				hs << "Mon hoc: " << endl;
				for (int i = 0; i < number; i++) {
					hs << mon_hoc[i].Ma_mon_hoc;  hs << "   QT: " << diem[x][i].GK; hs << "  CK: " << diem[x][i].CK;
					hs << endl;
				}
			}
			cout << "MISSON COMPLETE :> \n";
			break;
		case 0:
			cout << " tam biet ban";
			delete[] mon_hoc;
			delete[] hoc_sinh;
			return 0;
			break;
		default:
			cout << "Khong hop le";
		}

		cin.ignore();
	try_again:
		cout << " Ban co muon tiep tuc ko\n";
		int check;
		cout << "(1) de tiep tuc\n";
		cout << "(0) de huy\n";
		cout << "Lua chon la: ";
		cin >> check;
		if (check != 1 && check != 0) {
			system("cls");
			cout << "Lua chon cua ban khong hop le\n";
			goto try_again;
		}
		if (!check) {
			cout << " tam biet ban";
			break;
		}
	}
	delete[]mon_hoc;
	delete[]hoc_sinh;
	return 0;

}

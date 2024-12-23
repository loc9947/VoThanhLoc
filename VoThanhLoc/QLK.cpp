#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct hanghoa {
    string loai;  // Loai hàng hóa ( cam, b??ii, tào)
    string nguongoc;  // Nguồn góc hàng hóa
    string tenNguoiNhap;  // Tên người nhập kho
    string ngayNhap;  // Ngày nh?p kho
    int soLuong;  // số lượng (kg)
    double giaTien;  // Giá tiền của hàng hóa
    string viTriLuuTru;  //vị trí cần lưu hàng hóa
};
typedef struct xuatkho {
    string loai;  // tên của hàng hóa 
    string daiLy;  // tên dại lý 
    string diaChivasdt;  // địa chỉ và sđt của đại lý
    string ngayXuat;  // Ngày xuất kho
    string tenNguoiXuat;  // Tên người xuất kho
    double soluong;  // Tsô luong can xuất
    double giatien;  // Giá tiềm thu đc
    string ngayHoanTat;  // Ngày dự đến
};
vector<hanghoa> hangnhapData;
vector<xuatkho> xuatkhoData;


void nhapkho() {
    hanghoa hh;
    cout << "Nhap ten loai hang hoa: ";
    getline(cin, hh.loai);
    cout << "Nhap ten nha vuon: ";
    getline(cin, hh.nguongoc);
    cout << "Nhap ten nguoi nhap kho: ";
    getline(cin, hh.tenNguoiNhap);
    cout << "Nhap ngay nhap kho (dd/mm/yyyy): ";
    getline(cin, hh.ngayNhap);
    cout << "Nhap so luong (kg): ";
    cin >> hh.soLuong;
    cout << "Nhap gia tien: ";
    cin >> hh.giaTien;
    cin.ignore();
    cout << "Nhap vi tri can luu: ";
    getline(cin, hh.viTriLuuTru);

    hangnhapData.push_back(hh);
    cout << "Da nhap hang hoa vao kho.\n";
};

void xuathang() {
    xuatkho xk;
    cout << "Nhap tên loai hang hoa xuat: ";
    getline(cin, xk.loai);
    cout << "Nhap ten dai ly: ";
    getline(cin, xk.daiLy);
    cout << "Nhap dia chi dai ly và sđt: ";
    getline(cin, xk.diaChivasdt);
    cout << "Nhap ngay xuat kho (dd/mm/yyyy): ";
    getline(cin, xk.ngayXuat);
    cout << "Nhap ten nguoi xuat kho: ";
    getline(cin, xk.tenNguoiXuat);
    cout << "Nhap so luong (kg): ";
    cin >> xk.soluong;
    cout << "Nhap gia tien thu lai: ";
    cin >> xk.giatien;
    cin.ignore();
    cout << "Nhap ngay du kien hang đen: \n";
    getline(cin, xk.ngayHoanTat);
    //ki?m tra hàng trong kho
    bool found = false;
    for (auto& hh : hangnhapData) {
        if (hh.loai == xk.loai) {
            if (hh.soLuong >= xk.soluong) {
                hh.soLuong -= xk.soluong;
                found = true;
                xk.giatien = xk.soluong * hh.giaTien / hh.soLuong; // Tính giá ti?n
                break;
            }
            else {
                cout << "Khong du so luong trong kho de xuat!\n";
                return;
            }
        }
    }

    if (!found) {
        cout << "Hang hoa khong ton tai trong kho.\n";
        return;
    }

    cin.ignore(); // Bỏ newline
    cout << "Nhap ngay hoan tat: ";
    getline(cin, xk.ngayHoanTat);

    xuatkhoData.push_back(xk);
    cout << "Da xuat hang hoa khoi kho.\n";
};

void hienThiNhapKho() {
    cout << "Danh sach hang hoa nhap kho:\n";
    for (const auto& hh : hangnhapData) {
        cout << "Loai:\n " << hh.loai << ", Nguon goc:\n " << hh.nguongoc
            << ", Ngay nhap:\n " << hh.ngayNhap << ", So luong:\n " << hh.soLuong
            << " tan, Gia tien:\n " << hh.giaTien << ", Vi tri:\n " << hh.viTriLuuTru << endl;
    }
};

void hienThiXuathang() {
    cout << "Danh sach hang hoa xuat kho:";
    for (const auto& xk : xuatkhoData) {
        cout << "Loai:\n " << xk.loai << ", Dai ly\n: " << xk.daiLy
            << ", Ngay xuat:\n " << xk.ngayXuat << ", Trong luong:\n " << xk.soluong
            << " tan, Gia tien:\n " << xk.giatien << ", Ngay hoan tat:\n " << xk.ngayHoanTat << endl;
    }
};
void thongke() {
    cout << "\nThong ke so luong hang hoa con lai trong kho:\n";
    for (const auto& hh : hangnhapData) {
        if (hh.soLuong > 0) {
            cout << "Loai: " << hh.loai << ", So luong: " << hh.soLuong << " tan \n";
        }
    }
};


int main() {
    hanghoa hh;
    xuatkho xk;
    int choice;
    do {
        cout << "Chuong trinh quan ly kho hang : \n";
        cout << "1. Nhap kho: \n";
        cout << "2. Xuat kho: \n";
        cout << "3. Hien thi danh sach nhap kho: \n ";
        cout << "4. Hien thi danh sach xuat kho: \n";
        cout << "5. Thong ke: \n";
        cout << "6. Thoat \n";
        cout << "Nhap lua chon: \n";
        cin >> choice;
        cin.ignore();  // Ignore newline character after choice

        switch (choice) {
        case 1:
            nhapkho();
            break;
        case 2:
            xuathang();
            break;
        case 3:
            hienThiNhapKho();
            break;
        case 4:
            hienThiXuathang();
            break;
        case 5:
            thongke();
            break;
        case 6:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!!!!!!! vui long chon lai \n";
        }
    } while (choice != 6);

    return 0;
}
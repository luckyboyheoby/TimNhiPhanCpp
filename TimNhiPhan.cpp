#include <stdio.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sapXep(int phanTu[], int soLuongPhanTu) {
	for(int i = 0; i < soLuongPhanTu; i++) {
		for(int j = 1; j < soLuongPhanTu - 1; j++) {
			if(phanTu[i] < phanTu[j]) {
				swap(phanTu[i], phanTu[j]);
			}
		}
	}
}

int timNhiPhan(int phanTu[], int pTuCanTim, int soLuongPhanTu) {
	int left = 0; int right = soLuongPhanTu - 1;
	
	while(left <= right) {
		
		int mid = (left + right) / 2;
	
		if(phanTu[mid] == pTuCanTim) {
			return mid;
		} else if(phanTu[mid] > pTuCanTim) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}	
	}
	
	return -1;		
}

int main() {
	int soPhanTu;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &soPhanTu);
	
	int *phanTu = new int[soPhanTu];
	
	//Nhap mang
	for(int i = 0; i < soPhanTu; i++) {
		printf("Nhap a[%d]: ", i);
		scanf("%d", &phanTu[i]);
	}
	
	//Nhap phan tu can tim
	int pTuCanTim;
	printf("Phan tu can tim: ");
	scanf("%d", &pTuCanTim);
	
	//Sap xep de tim kiem nhi phan
	sapXep(phanTu, sizeof(phanTu));
	
	//Goi ham
	int kq = timNhiPhan(phanTu, pTuCanTim, sizeof(phanTu));
	if(kq == -1) {
		printf("\nKhong tim thay!");
	} else {
		printf("\nTim thay o %d", kq + 1);
	}
	
	return 0;
}

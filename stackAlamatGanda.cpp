#include <iostream>
#include <malloc.h>

// arah alamat (next) dari atas -> bawah

using namespace std;

struct Stack
{
	int info;
	Stack *kanan;
	Stack *kiri;
};

Stack *bottom, *top;

void push(int infoBaru);
void pop();
void buatStack();
bool cekKosong();
void cetak();
void cetak2();

int main()
{

	buatStack();
	push(12);
	push(4);
	push(3);
	push(20);
        push(24);
	cout << endl;
	cetak();
	cout << endl;
	cetak2();
	cout << endl;
	pop();

	cetak();
	cout << endl;
	cetak2();
}

void buatStack()
{
	top = NULL;
	bottom = NULL;
}

bool cekKosong()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(int infoBaru)
{
	Stack *nodeBaru = (Stack *)malloc(sizeof(Stack));
	nodeBaru->info = infoBaru;
	// Stack *bantu -> next = NULL;

	if (cekKosong())
	{
		top = nodeBaru;
		bottom = nodeBaru;
		bottom->kiri = NULL;
	}
	else
	{

		//		bantu = top;
		//		top = nodeBaru;
		//		nodeBaru-> next = bantu;
		top->kanan = nodeBaru;
		nodeBaru->kiri = top;
		nodeBaru->kanan = NULL;
		top = nodeBaru;
	}
}

void pop()
{

	Stack *hapus, *bantu;
	int ip;

	if (cekKosong())
	{
		cout << "Data masih Kosong Boss" << endl;
	}
	else
	{

		ip = top->info;
		hapus = top;
		top = top->kiri;
		top->kanan = NULL;
		free(hapus);
	}
}

void cetak()
{
	Stack *bantu;

	if (cekKosong())
	{
		cout << "Data masih Kosong Boss" << endl;
	}
	else
	{
		bantu = top;
		if (bottom == top && bottom != NULL)
		{
			cout << bantu->info << endl;
		}
		else
		{
			while (bantu != NULL)
			{

				cout << bantu->info << endl;
				bantu = bantu->kiri;
			}
		}
	}
}

void cetak2()
{
	Stack *bantu;

	if (cekKosong())
	{
		cout << "Data masih Kosong Boss" << endl;
	}
	else
	{
		bantu = bottom;
		if (bottom == top && bottom != NULL)
		{
			cout << bantu->info << endl;
		}
		else
		{
			while (bantu != NULL)
			{

				cout << bantu->info << endl;
				bantu = bantu->kanan;
			}
		}
	}
}

#include<iostream>
#include<fstream>
using namespace std;
ifstream import("C:\\Users\\nanmu\\Desktop\\input sentence.txt");
ofstream export("C:\\Users\\nanmu\\Desktop\\output rule.txt");
#include<string>
char a[10];      // �ַ����Ĵ���
int advance=0;   // �ַ���С�꣬��ʾʹIPָ����һ�������
void E();        // ����ʶ����,��ʾ����E->TE'
void E1();       // ����ʶ����,��ʾ����E'->+TE'/��
void T();        // ����ʶ����,��ʾ����T->FT'
void T1();       // ����ʶ����,��ʾ����T'->*FT'/��
void F();        // ����ʶ����,��ʾ����F->(E)/i
int main()       // ������
{

	export<<"please input the right sentence(end with #)��";//������ʾ
    import>>a;
	E();         // ���׸��Ƶ�ʽE��ʼ
	if((a[advance]=='#'))
      export<<"The sentence is right,success!\n";
    else
      export<<"No the signal of #,fail!\n";

	return 0;
}

void E()       // ����ʶ����
{
    export<<"E->TE'\n";
    T();
    E1();
}
void E1()
{
	if(a[advance]=='+')
	{
        export<<"E'->+TE'\n";  //���ʹ��E'����
	    advance++;     //����ǡ�+�������ȡ��һ�ַ�
		T(); //����E'->+TE�����Ҳ����Ŵ���˳�򣬵����������ս���Ĺ���
		E1();
	}
        else
          export<<"E'->��\n";
}
void T()
{
    export<<"T->FT'\n";
	F();    //����T->FT'�����Ҳ����Ŵ���˳�򣬵����������ս���Ĺ���
	T1();
}
void T1()
{
	if(a[advance]=='*')    //����ǡ�*�������ȡ��һ�ַ�
	{
		export<<"T'->*FT'\n";
        advance++;
		F();//����T'->*FT'�����Ҳ����Ŵ���˳�򣬵����������ս���Ĺ���
		T1();
	}
	else
        export<<"T'->��\n";
}
void F()
{
	if(a[advance]=='i')  //����ǡ�i�������ȡ��һ�ַ�
   {
      export<<"F->i\n";
      advance++;
   }
   else if (a[advance]=='(')  //����ǡ�(�������ȡ��һ�ַ�
   {
        advance++;
        E();   //����F->(E)�����Ҳ����Ŵ���˳�򣬵��÷��ս��E�Ĺ���
		if(a[advance]==')'){
		        export<<"F->(E)\n";
                advance++;
			}
			else{
			export<<"\n ()is not matching, error! \n";
             exit (0); //����������������
       }
   }
  else{
	    export<<"\n ()is not matching, error! \n";
        exit(0); //����������������
  }
 }

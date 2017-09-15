#include<iostream>
#include<fstream>
using namespace std;
ifstream import("C:\\Users\\nanmu\\Desktop\\input sentence.txt");
ofstream export("C:\\Users\\nanmu\\Desktop\\output rule.txt");
#include<string>
char a[10];      // 字符串的存入
int advance=0;   // 字符串小标，表示使IP指向下一输入符号
void E();        // 功能识别函数,表示规则E->TE'
void E1();       // 功能识别函数,表示规则E'->+TE'/ε
void T();        // 功能识别函数,表示规则T->FT'
void T1();       // 功能识别函数,表示规则T'->*FT'/ε
void F();        // 功能识别函数,表示规则F->(E)/i
int main()       // 主函数
{

	export<<"please input the right sentence(end with #)：";//输入提示
    import>>a;
	E();         // 从首个推导式E开始
	if((a[advance]=='#'))
      export<<"The sentence is right,success!\n";
    else
      export<<"No the signal of #,fail!\n";

	return 0;
}

void E()       // 功能识别函数
{
    export<<"E->TE'\n";
    T();
    E1();
}
void E1()
{
	if(a[advance]=='+')
	{
        export<<"E'->+TE'\n";  //输出使用E'规则
	    advance++;     //如果是“+”，则读取下一字符
		T(); //根据E'->+TE规则右部符号串的顺序，调用其他非终结符的规则
		E1();
	}
        else
          export<<"E'->ε\n";
}
void T()
{
    export<<"T->FT'\n";
	F();    //根据T->FT'规则右部符号串的顺序，调用其他非终结符的规则
	T1();
}
void T1()
{
	if(a[advance]=='*')    //如果是“*”，则读取下一字符
	{
		export<<"T'->*FT'\n";
        advance++;
		F();//根据T'->*FT'规则右部符号串的顺序，调用其他非终结符的规则
		T1();
	}
	else
        export<<"T'->ε\n";
}
void F()
{
	if(a[advance]=='i')  //如果是“i”，则读取下一字符
   {
      export<<"F->i\n";
      advance++;
   }
   else if (a[advance]=='(')  //如果是“(”，则读取下一字符
   {
        advance++;
        E();   //根据F->(E)规则右部符号串的顺序，调用非终结符E的规则
		if(a[advance]==')'){
		        export<<"F->(E)\n";
                advance++;
			}
			else{
			export<<"\n ()is not matching, error! \n";
             exit (0); //正常结束程序运行
       }
   }
  else{
	    export<<"\n ()is not matching, error! \n";
        exit(0); //正常结束程序运行
  }
 }

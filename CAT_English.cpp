#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;
int d,f,g,deg=0;
char *id1;
 
void num();
void rule();
void signin();
void signup();
int wenjian(char*user,char*psw,string str1,string str2);
int search(char* user,char* pwd);
int add(string str1,string str2);
void choice();
void word(int cho1);
void phrase(int cho1);
void sents(int cho1);
void tc();
void learnlevel(char* user,char* pwd);

struct account
{
	char id[4];
    char psw[6];
     int  deg1;
};
account p;

void main()
{
	
	num();
	rule();
	choice();
}

 void rule()//游戏规则
 {
	 int cho;
	 cout<<"***********************************************************************"<<endl;
     cout<<"***                                                                 ***"<<endl;
     cout<<"***                   欢迎来到这里学习                              ***"<<endl;
	 cout<<"***  1.若是第一次使用请注册账号，以便保存记录                       ***"<<endl;
	 cout<<"***  2. 本软件有三个等级:                                           ***"<<endl;
     cout<<"***                    （1）单词学习                                ***"<<endl;
     cout<<"***                    （2）词组学习                                ***"<<endl;
     cout<<"***                    （3）短句学习                                ***"<<endl;
	 cout<<"***  3. 屏幕上将按等级随机出现单词、词组和短句，请同学输入相应答案  ***"<<endl;
	 cout<<"***  4. 一次做题的正确率达到90%以上可依次晋级                       ***"<<endl;
	 cout<<"***                                                                 ***"<<endl;
	 cout<<"***********************************************************************"<<endl;
	 cout<<endl;
	 cout<<"请选择：（0）注册账号  （1）登录  （2）退出"<<endl;
	 cin>>cho;
	 if(cho!=0&&cho!=1&&cho!=2)
	 {
		 cout<<"输入错误，请重新输入！"<<endl;
	     cin>>cho;
	 }
	 switch(cho)
	 {
	 case 0   :signup();break;
	 case 1:  signin();break;
	 case 2: tc();break;
	 }
 }

 void tc()//退出
 {
	 int cho2,t2;
	 cout<<"***********************************************************************"<<endl;
	 cout<<"***         确定退出吗？                                            ***"<<endl;
	 cout<<"***                   (0)是的                                       ***"<<endl;
	 cout<<"***                   (1)取消                                       ***"<<endl;
	 cout<<"***********************************************************************"<<endl;
	 cout<<endl<<endl;
	 cin>>cho2;
	 if(cho2>=2||cho2<0)
	 {
		 cout<<"输入错误，请重新输入\n\n";
	     cout<<"***********************************************************************"<<endl;
	     cout<<"***         确定退出吗？                                            ***"<<endl;
	     cout<<"***                   (0)是的                                       ***"<<endl;
	     cout<<"***                   (1)取消                                       ***"<<endl;
	     cout<<"***********************************************************************"<<endl;
		 cin>>cho2;
	 }
	 switch(cho2)
	 {
	 case 1: choice();break;
	 case 0: 
		     learnlevel(p.id,p.psw);
		     cout<<"退出学习\n";
			 for(t2=200000000;t2>0;t2--);
		     exit(0);break;
	 default:tc();
	 }
 }

void choice()//选择界面函数
{
	int cho1,y,MAX,t2;
	for(t2=100000000;t2>0;t2--);
	system("cls");
	switch(deg)
	{
	case 0: cout<<endl<<"当前学习阶段为： 单词学习阶段"<<endl<<endl;MAX=d;break;
	case 1: cout<<endl<<"当前学习阶段为： 词组学习阶段"<<endl<<endl;MAX=f;break;
	case 2: cout<<endl<<"当前学习阶段为： 短句学习阶段"<<endl<<endl;MAX=g;break;
	}
	
	cout<<endl;
	cout<<"***********************************************************************"<<endl;
	cout<<"***                                                                 ***"<<endl;
	cout<<"***                  欢迎您开始英语学习！                           ***"<<endl;
	cout<<"***               请输入本次想要学习的题目数量：                    ***"<<endl;
    cout<<"***                 范围请在0~~"<<MAX<<"之间                                ***"<<endl;
    cout<<"***                                                                 ***"<<endl;
	cout<<"***              屏幕上将随机出中英文，请同学输入相应答案           ***"<<endl;
	cout<<"***                                                                 ***"<<endl;
	cout<<"***********************************************************************"<<endl;
	cout<<endl<<"题目数：";
	cin>>cho1;
	cout<<endl;
	system("cls");
	if(cho1>MAX||cho1<=0)
	 {
		 cout<<"输入错误，请重新输入题目数\n\n";
	     cout<<"***********************************************************************"<<endl;
		 cout<<"***                                                                 ***"<<endl;
	     cout<<"***         请重新输入学习题目数量：                                ***"<<endl;
		 cout<<"***                 范围请在0~~"<<MAX<<"之间                                ***"<<endl;
		 cout<<"***                                                                 ***"<<endl;
	     cout<<"***********************************************************************"<<endl<<endl;
		 cout<<"题目数：";
		 cin>>cho1;
		 cout<<endl;
	 }
	 cout<<"***********************************************************************"<<endl;
     cout<<"***                                                                 ***"<<endl;
	 cout<<"***         请确定学习题目数目：                                    ***"<<endl;
	 cout<<"***                               "<<cho1<<"                                 ***"<<endl;
	 cout<<"***                    (1)是的           （2）否                    ***"<<endl;
	 cout<<"***********************************************************************"<<endl<<endl;
	 cin>>y;
	 system("cls");
	 switch(y)
	 {
	 case 1: cout<<"开始学习"<<endl;
		     if(deg==0) 
			 {
				 cout<<endl<<"      单词学习阶段："<<endl<<endl;
				 word(cho1);
			 }
			 if(deg==1)
			 {
				cout<<endl<<"       词组学习阶段："<<endl<<endl; 
					 phrase(cho1);
			 }
			 else
			 {
				 cout<<endl<<"      短句学习阶段："<<endl<<endl; 
				 sents(cho1);
			 }
			 break;
	 case 2:choice();break;
	 }
}

void word(int cho1)   //抽取随机单词
{
	int i=0,y,t1,t2,w,sum=0,cal=0,d;
	char c;
	string a[1000],b[1000];//b放中文，a放英文
	int sstr[1000];  //只能放1000
	string str,str1,str2;
	fstream fp;                     //打开文件，读取文件，放进数组,随机读取i，第一维用i抽，输入相应答案，只要与前一或后一相同即可。
	fp.open("word.txt",ios::in);  //再用随机数选cho1里面其中一个，将最后有效数字放在其位置，数组长度减1
	if(!fp)
	{
		printf("单词库打开失败\n");
		exit(0);
	}
	fp>>d;
	if(d<0)
	{
		printf("单词库打开错误\n");
		exit(0);
	}
	getline(fp,str, ':');          //从fin对象中向item对象中读取字符串，遇到“:”字符则完成一次读取  
    while(fp)                        //只要没读到文件尾，则循环读取并输出读取内容  
	{
		a[i]=str;
		getline(fp,str, ':');           //把所有东西放到数组里       
		b[i]=str;
        getline(fp,str, ':');
		i++;
    }  
	if(i!=d)
	{
		printf("单词库打开错误\n");
		exit(0);
	}
	fp.close();
	for(y=0;y<=i;y++)                //i=max
	{
		sstr[y]=y;           //抽取数字的数组
	}
	int end = i-1;
	for(w=0;w<cho1;w++)               //在题目数目里选择题目
	{
		srand(int(time(0)));
		t1=rand()%2;    //出现随机整数
		srand(int(time(0)));
		if(end==0) t2=0;
		else
		{
			t2=rand()%end;
		}
		t2 =sstr[t2];
	    sstr[t2] = sstr[end]; //把尾部有效数字放到前面
		end--;
		if(t1%2==0)
		{
				str = a[t2];
				str2 = b[t2];
		}//用随机数得到单词
		else 
		{
			str = b[t2];
			str2 = a[t2];
		}
		cout<<endl<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		cout<<"第"<<w+1<<"题："<<endl<<endl;
		cout<<"                "<<str<<endl;
		cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
		if(w==0) cin.ignore(1,'\n');
		while(( c = cin.get())!='\n')             //能不能不用回车结尾
		{
			cout.put(c);
			str1+=c;
		}
		if( str1 == str2 )
		{
			sum++;
			cout<<endl<<"回答正确！  请继续下一题。"<<endl;
			for(t2=150000000;t2>0;t2--);
			system("cls");
		}

		while( str1 != str2 )
		{
			str1="";
			cout<<"回答错误，请重新输入答案。"<<endl<<endl;
			cout<<"正确答案为：     "<<str2<<endl;
			for(t2=1000000000;t2>0;t2--);
			system("cls");
			cout<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		    cout<<"第"<<w+1<<"题："<<endl<<endl;
			cout<<"                "<<str<<endl;
			cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
			
		    while(( c = cin.get())!='\n')             //能不能不用回车结尾
			{
				cout.put(c);
				str1+=c;
			}
			cal++;
			if(str1== str2)  cout<<endl<<"回答正确！  请继续下一题。"<<endl<<endl;
			for(t2=150000000;t2>0;t2--);
		}
		str1="";
		system("cls");
	}
	cout<<"答题结束。本次学习结果为："<<endl;
	cout<<"                            答对题数为："<<sum<<endl;
	cout<<"                            答错题数为："<<cal<<endl;
	cout<<"                            一次答对率为："<<((float)sum/cho1)*100<<"%"<<endl<<endl;
	if(((float)sum/cho1)<0.9)
	{
		cout<<"         很抱歉，正确率未达90%"<<endl;
		cout<<"         是否继续学习？"<<endl;
		cout<<"                       (0)继续"<<endl;
		cout<<"                       (1)退出"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:choice();break;
		case 1:tc();break;
		}
	}
	else 
	{
		cout<<"        恭喜！正确率达到90%"<<endl;
		cout<<"        你已成功晋级！是否继续学习："<<endl;
		cout<<"                       (0)继续"<<endl;
		cout<<"                       (1)退出"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:deg=1;
			   choice();break;
		case 1:tc();break;
		}
	}
}

void phrase(int cho1)   //抽取随机词组
{   
	int i=0,y,t1,t2,w,sum=0,cal=0,d;
	char c;
	string a[1000],b[1000];//b放中文，a放英文
	int sstr[1000];  //只能放1000
	string str,str1,str2;
	fstream fp;                     //打开文件，读取文件，放进数组,随机读取i，第一维用i抽，输入相应答案，只要与前一或后一相同即可。
	fp.open("phrase.txt",ios::in);  //再用随机数选cho1里面其中一个，将最后有效数字放在其位置，数组长度减1
	if(!fp)
	{
		printf("词组库打开失败\n");
		exit(0);
	}
	fp>>d;
	if(d <0)
	{
     cout<<"词组库打开错误"<<endl;;
	 exit(0);
	}
	getline(fp,str, ':');          //从fin对象中向item对象中读取字符串，遇到“:”字符则完成一次读取  
    while(fp)                        //只要没读到文件尾，则循环读取并输出读取内容  
	{
		a[i]=str;
		getline(fp,str, ':');           //把所有东西放到数组里       
		b[i]=str;
        getline(fp,str, ':');
		i++;
    }  
	if(i!=d)
	{
		cout<<"词组库打开错误"<<endl;
		exit(0);
	}
	fp.close();
	for(y=0;y<=i;y++)                //i=max
	{
		sstr[y]=y;           //抽取数字的数组
	}
	int end = i - 1;
	for(w=0;w<cho1;w++)               //在题目数目里选择题目
	{
		srand(int(time(0)));
		t1=rand()%i;    //出现随机整数
	    if(!end)
		{
		   t2=0;
		}
		else
		{
			srand(int(time(0)));
			t2=rand()%end;
		}
		t2 = sstr[t2];
	    sstr[t2] = sstr[end]; //把尾部有效数字放到前面
		end--;
		if(t1%2==0)
		{
			str = a[t2];
			str2 = b[t2];
		}//用随机数得到单词
		else
		{
			str = b[t2];
			str2 = a[t2];
		}
        cout<<endl<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		cout<<"第"<<w+1<<"题："<<endl;
		cout<<"                "<<str<<endl;
		cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
		if(w==0) cin.ignore(1,'\n');
		while(( c = cin.get())!='\n')             //能不能不用回车结尾
		{
			cout.put(c);
			str1+=c;
		}
		if( str1 == str2 )
		{
			sum++;
			cout<<endl<<"回答正确！  请继续下一题。"<<endl;
			for(t2=150000000;t2>0;t2--);
			system("cls");
		}
		while( str1 != str2 )
		{
			str1="";
			cout<<"回答错误，请重新输入答案。"<<endl<<endl;
			cout<<"正确答案为：     "<<str2<<endl;
			for(t2=1000000000;t2>0;t2--);
			system("cls");
			cout<<endl<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		    cout<<"第"<<w+1<<"题："<<endl<<endl;
			cout<<"                "<<str<<endl;
			cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
			
		    while(( c = cin.get())!='\n')             //能不能不用回车结尾
			{
				cout.put(c);
				str1+=c;
			}
			cal++;
			if(str1== str2)  cout<<endl<<"回答正确！  请继续下一题。"<<endl<<endl;
			for(t2=150000000;t2>0;t2--);
			system("cls");
		}
		str1="";
	}
	cout<<"答题结束。本次学习结果为："<<endl;
	cout<<"                            答对题数为："<<sum<<endl;
	cout<<"                            答错题数为："<<cal<<endl;
	cout<<"                            一次答对率为："<<((float)sum/cho1)*100<<"%"<<endl<<endl;
	if(((float)sum/cho1)<0.9)
	{
		cout<<"         很抱歉，正确率未达90% 你已降级。"<<endl;
		cout<<"         是否继续学习？"<<endl;
		cout<<"                       (0)继续"<<endl;
		cout<<"                       (1)退出"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:deg=0;
			   choice();break;
		case 1:tc();break;
		}
	}
	else 
	{
		cout<<"        恭喜！正确率达到90%"<<endl;
		cout<<"        你已成功晋级！是否继续学习："<<endl;
		cout<<"                       (0)继续"<<endl;
		cout<<"                       (1)退出"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:deg=2;
			   choice();break;
		case 1:tc();break;
		}
	}
}

void sents(int cho1)   //抽取随机短句
{   
	int i=0,y,t1,t2,w,sum=0,cal=0,d;
	char c;
	string a[1000],b[1000];//b放中文，a放英文
	int sstr[1000];  //只能放1000
	string str,str1,str2;
	fstream fp;                     //打开文件，读取文件，放进数组,随机读取i，第一维用i抽，输入相应答案，只要与前一或后一相同即可。
	fp.open("sents.txt",ios::in);  //再用随机数选cho1里面其中一个，将最后有效数字放在其位置，数组长度减1
	if(!fp)
	{
		cout<<"短句库打开失败\n";
		exit(0);
	}
	fp>>d;
	if(d <0)
	{
     cout<<"短句库打开错误"<<endl;;
	 exit(0);
	}
	getline(fp,str, ':');          //从fin对象中向item对象中读取字符串，遇到“:”字符则完成一次读取  
    while(fp)                        //只要没读到文件尾，则循环读取并输出读取内容  
	{    
		a[i]=str;
		getline(fp,str, ':');           //把所有东西放到数组里       
		b[i]=str;
        getline(fp,str, ':');
		i++;
    }  
	if(i!=d)
	{
		cout<<"短句库打开错误"<<endl;
		exit(0);
	}
	fp.close();
	for(y=0;y<=i;y++)                //i=max
	{
		sstr[y]=y;           //抽取数字的数组
	}
	int end = i - 1;
	for(w=0;w<cho1;w++)               //在题目数目里选择题目
	{
		srand(int(time(0)));
		t1=rand()%i;    //出现随机整数
		if(!end) { t2=0;}
		else
		{
			srand(int(time(0)));
			t2=rand()%end;
		}
		t2 = sstr[t2];
	    sstr[t2] = sstr[end]; //把尾部有效数字放到前面
		end--;
		if(t1%2==0)
		{ 
			str = a[t2];
			str2 = b[t2];
		}//用随机数得到单词
		else
		{
			str = b[t2];
			str2 = a[t2];
		}
        cout<<endl<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		cout<<"第"<<w+1<<"题："<<endl;
		cout<<"                "<<str<<endl;
		cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
		if (w==0)cin.ignore(1,'\n');
		while(( c = cin.get())!='\n')
		{
			cout.put(c);
			str1+=c;
		}
		if( str1 == str2 )
		{
			sum++;
			cout<<endl<<"回答正确！  请继续下一题。"<<endl;
			for(t2=150000000;t2>0;t2--);
			system("cls");
		}
		while( str1!= str2 )
		{
			str1="";
			cout<<"回答错误，请重新输入答案。"<<endl<<endl;
			cout<<"正确答案为：     "<<str2<<endl;
			for(t2=1000000000;t2>0;t2--);
			system("cls");
			cout<<endl<<"当前已做题数"<<w<<"/"<<cho1<<endl;
		    cout<<"第"<<w+1<<"题："<<endl<<endl;
			cout<<"                "<<str<<endl;
			cout<<"请输入相应的英文或中文(按回车确认输入答案)"<<endl;
			cin.clear();
			while(( c = cin.get())!='\n')
			{
				cout.put(c);
				str1+=c;
			}
			cal++;
			if(str1==str2)  cout<<endl<<"回答正确！  请继续下一题。"<<endl<<endl;
			for(t2=150000000;t2>0;t2--);
			system("cls");
		}
		str="";
	}
	cout<<"  答题结束。本次学习结果为："<<endl;
	cout<<"                            答对题数为："<<sum<<endl;
	cout<<"                            答错题数为："<<cal<<endl;
	cout<<"                            一次答对率为："<<((float)sum/cho1)*100<<"%"<<endl<<endl;
	if(((float)sum/cho1)<0.9)
	{
		cout<<"         很抱歉，正确率未达90% 您已降级"<<endl;
		cout<<"         是否继续学习？"<<endl;
		cout<<"                       (0)继续"<<endl;
		cout<<"                       (1)退出"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:deg--;
			   choice();break;
		case 1:tc();break;
		}
	}
	else 
	{
		cout<<"        恭喜！正确率达到90%"<<endl;
		cout<<"        你已成功完成学习。"<<endl;
     	cout<<"        是否退出学习："<<endl;
		cout<<"                      (0)是"<<endl;
		cout<<"                      (1)否"<<endl;
		cin>>y;
		switch(y)
		{
		case 0:tc();break;  
		case 1: choice();break;
		}
	}
}

void signup()//注册
{
	int t2=0;
	string str1,str2;
	int u=0,judge1=1,judge2=2;
    char cho3; 
    unsigned i=0,k=0;
	cout<<"请输入您的用户名（必须为3位纯英文）"<<endl;
	cin.clear();
	cin>>p.id;
	cin.clear();
	while(!u)
	{
		u=1;
		cout<<endl;
		while(i<strlen(p.id))
		{
			if((p.id[i] >='z' || p.id[i] <='a')&&(p.id[i]<='A'||p.id[i]>='Z'))
			{
				cout<<p.id[i];
				judge1=0;
				u=0;
			}
			i++;
		}
		if(strlen(p.id)!=3 ||judge1==0)//判断用户名形式的正确
		{
			cout<<"您输入不正确!用户名必须为3位纯字母!\n";
		    cout<<"请重新输入用户名（3位纯字母)："<<endl;
		    u=0;
			cin.clear();
			cin>>p.id;
		}
	}
	str1=p.id;
	str1+=':';
	cout<<"请输入您的密码(必须为5位纯数字)：\n";
	cin.clear();
	cin>>p.psw;
	u=0;
	while(!u)
	{
		u=1;
	    k=0;
		while(k<strlen(p.psw))
		{
			if(p.psw[k]<'0'||p.psw[k]>'9')
			{
			judge2=0;
			u=0;
			}
		k++;
		}
		if(strlen(p.psw)!=5 ||judge2==0)//判断密码形式的正确性
		{
			u=0;
			cout<<"您的输入不正确!密码必须为5位纯数字!\n";
			cout<<"请重新输入密码(5位纯数字)：";
			cin.clear();
			cin>>p.psw;
		}
	}
	str2=p.psw;
	str2+=':';
	if(wenjian(p.id,p.psw,str1,str2)==0)
	{
		system("cls");
		cout<<"恭喜你注册成功！"<<endl;//注册成功
		for(t2=150000000;t2>0;t2--);
		choice();
	}
	else
	{
		system("cls");
		cout<<"你输入的账户已存在，注册失败！"<<endl;
		cout<<"请选择：     （1）重新注册   (2)任意键退出"<<endl;
		cin>>cho3;
		if(cho3=='1') signup();
		else tc();
	}
}

int wenjian(char*user,char*psw,string str1,string str2)//检测用户名是否重复
{
	if(search(user,psw)==1) return 1;   //有相同返回1
	else add(str1,str2); return 0;
}

int search(char* user,char* pwd)//判断帐号是否相同，相同返回1
{
	string id1,psw1,deg2;
	const char*user1;
	ifstream fp("user.txt",ios::in);
	if(!fp)
	{
		cout<<"用户信息调取失败\n";
		exit(0);
	}
	while (fp)
	{
		getline(fp,id1, ':'); 
		getline(fp,psw1, ':');
		getline(fp,deg2, ':');
		user1 = id1.c_str();
		if(strcmp(user,user1)==0)//相同返回值为0
		{
			return 1;
		}
	}
	fp.close();
	return 0;
}

int add(string str1,string str2)//添加用户信息
{
	fstream fp;
	fp.open("user.txt",ios::app);
	if(!fp)
	{
		cout<<"用户信息录入失败\n";
		exit(0);
	}
	fp<<str1<<str2<<"0:";
	fp.close();
	return 0;
}

void num()//读取词库容量
{
    fstream fp1;           //打开单词库        
	fp1.open("word.txt",ios::in);
	if(!fp1)
	{
		printf("单词库打开失败\n");
		exit(0);
	}
	fp1>>d;
	if(d<0)
	{
		printf("单词库打开错误\n");
		exit(0);
	}
	fp1.close();
	fstream fp2;                 //打开词组库
	fp2.open("phrase.txt",ios::in);  
	if(!fp2)
	{
		printf("词组库打开失败\n");
		exit(0);
	}
	fp2>>f;
	if(f<0)
	{
		cout<<"词组库打开错误"<<endl;
	    exit(0);
	}
	fp2.close();
	fstream fp3;                 //打开短句库  
	fp3.open("sents.txt",ios::in);  
	if(!fp3)
	{
		printf("短句库打开失败\n");
		exit(0);
	}
	fp3>>g;
	if(g <0)
	{
		cout<<"短句库打开错误"<<endl;;
	    exit(0);
	}
	fp3.close();
}

void learnlevel(char* user,char* pwd)
{
	string id1[1000],psw1[1000],deg2[1000];
	const char*user2;
	const char*psw2;
	int i=0;
	fstream fp;
	fp.open("user.txt",ios::app);
	if(!fp)
	{
		cout<<"用户信息更新失败\n";
		exit(0);
	}
	fp.seekg(0);
	while (fp)
	{
		getline(fp,id1[i], ':'); 
		getline(fp,psw1[i], ':');
		user2 = id1[i].c_str();
		psw2 = psw1[i].c_str();
		if((strcmp(user,user2)==0)&&(strcmp(pwd,psw2)==0))//相同返回值为0
		{
			deg2[i]=deg;
			fp<<deg2[i]<<':';
		}
		else getline(fp,deg2[i], ':');
		i++;
	}
	fp.close();
	switch(deg)
	{
	case 0: cout<<endl<<"当前学习阶段为： 单词学习阶段"<<endl<<endl;break;
	case 1: cout<<endl<<"当前学习阶段为： 词组学习阶段"<<endl<<endl;break;
	case 2: cout<<endl<<"当前学习阶段为： 短句学习阶段"<<endl<<endl;break;
	}
}

void signin()
{
	string str1,str2;
	string id1,psw1,deg2;
	const char*user2;
	const char*psw2;
	int m=0,t2;
	unsigned cho4;
	cout<<"请输入您的用户名（必须为3位纯英文）"<<endl;
	cin.clear();
	cin>>p.id;
	cin.clear();
	str1=p.id;
	str1+=':';
	cout<<"请输入您的密码(必须为5位纯数字)：\n";
	cin.clear();
	cin>>p.psw;
	cin.clear();
	str2=p.psw;
	str2+=':';
	fstream fp;
	fp.open("user.txt",ios::in);
	if(!fp)
	{
	    cout<<"用户信息调取失败\n";
		exit(0);
	}
	while (fp)
	{
		getline(fp,id1, ':'); 
		getline(fp,psw1, ':');
		getline(fp,deg2, ':');
		user2 = id1.c_str();
		psw2 = psw1.c_str();
		if((strcmp(p.id,user2)==0)&&(strcmp(p.psw,psw2)==0))//相同返回值为0
		{
				cout<<"登陆成功！"<<endl<<endl;
				if(deg2=="0")
				{
					deg=0;
				
                if(deg2=="1")
				{
					deg=1;
                   if(deg2=="2")
				   {
					deg=2;
				}
				}
				}
				switch(deg)
				{
				case 0:
				case 1: 
				case 2:choice();break;
				default:cout<<"信息读取错误"<<endl;
					    exit(0);
				}
				fp.close();
		   }
	   else
	   {
			   cout<<"用户名或密码输入错误，请选择："<<endl;
	           cout<<"                              (1)重新输入"<<endl;
	           cout<<"                              (2)重新注册"<<endl;
	           cout<<"                              (3)退出"<<endl;
	           cin>>cho4;
	           while((cho4!=1)&&(cho4!=2)&&(cho4!=3))
			   {
				  
				   cout<<"输入错误，请重新输入！"<<endl;
				   cin>>cho4;
			   }
			   for(t2=150000000;t2>0;t2--);
			    system("cls");
			   switch(cho4)
			   {
	                  case 1:signin();break;
	                  case 2:signup();break;
	                  case 3:tc();break;
	            }
		}
	}
}
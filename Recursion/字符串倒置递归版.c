/*
	�ݹ���ð潫�ַ������ã���C�����Ѿ�ӵ��һ������strrev(char  *);
	�ݹ����ȿ��ǵ��ǵݹ������������
*/

#include<stdio.h>

void convertArryLitter(char *p, int n);

void convertArryLitter(char *p, int count)
{
	char temp;

	if(count > 1)  //��һ���ַ������ֻ��һ���ַ�ʱ���Ϳ��Խ����ݹ��ˡ�
	{
		temp = p[0];
		p[0] = p[count-1];    //��β�໥������
		p[count-1] = temp;

		convertArryLitter(p+1, count-2);
	}
}

void main(void)
{
	char  a[20];
	int n;

	printf("������һ���ַ�����");
	gets(a);

	n = sizeof(a);

	convertArryLitter(a, n);
	printf("%s\n",a);
}
/*
	s : "abcdefg" count :7

	char s[] = "abcdefg";
	converTArryLitter(s, 7)

s -> a b c d e f g \0
	 0 1 2 3 4 5 6 7
	s1 count1;7
	   0 1 2 3 4 5 6
	   s2,count2;5
	     0 1 2 
		s3 count3;3
		   0 1 
		  s4 count4;1
*/
/*
	���ô��ݳ��ȵģ����ǻ��Ǵ��ݳ��ȵĸ�����Щ��ӦΪ��Щ������Ҫ��
	�ַ�����һ���ֵ��á�
  
	char * conver(char *string);
    char * conver(char *string)
	{
		char * p = string ;
		char * left = p;
		char temp;
	
		if( p != NULL)  //�ж�һ�����ָ��ǿջ���Ҫ�ġ�
		{
			
			while(*string++)
				;
			string-=2;   //�ҵ�ĩβ��ע����-2�����������־��string��������һ��++
			while(left < string)
			{
				temp = *left;
				*left++ = *string;
				*string-- = temp;     //ָ��Ĳ��� ���ͺ��Լ� �ͺ�����
			  }
		}

		return p;
			
	}


	
*/
/*
�����Ŀͨ���ǿ����������棬һ�Ƕ�ָ����ַ�������⣬�����Ƿ���кϷ��Լ�飬
�����������Ϊ��ָ��ʱ�Ƿ���м�飬���Ƿ���ֵ�Ƿ���ǡ������ʹ��ͨ������
�����˷�ת����ַ���ָ�룬Ҳ�����ڷ���ֵ���ٷ���һ�£�����strcpy����ʵ�ֵ�������
��ʵ���е��ĵ������Ǵ�Ҷ������˵ģ��Ǿ���Unicode���⣬���������ַ���ָ��ָ�����Unicode�ַ�����
��ô��ת��ʱ��Ͳ���һ���ַ�һ���ַ��Ĵ����ˣ������ƺ���������Թٶ�û����һ���й�Ҫ��
������ڱ��Ի�����������������⣬�ҽ�������࿼�����Թ�ѯ��һ���Ƿ���Ҫ����Unicode��
�����Ե�ʱ����Ϊ�����Թ�Ū�ĺܽ��ţ�Ҳ��������㣬д��������׼������ȥʱ����������
*/
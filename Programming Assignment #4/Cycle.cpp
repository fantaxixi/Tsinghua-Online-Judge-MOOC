#include<iostream>
#include<cstring>
using namespace std;
#define NUM 100001
int* builenext(char* P)
{
	int s = strlen(P), i=0;
	int* N = new int[s];
	int t = N[0] = -1;
	while(i < s-1)
	{
		if(t<0 || P[t]==P[i])
		{
			t++;
			i++;
			N[i] = t;
		}
		else t = N[t];
	}
	return N;
}
int KMP(char* T, char* P)
{
	int* next = builenext(P);
	int s1 = strlen(T), i=0;
	int s2 = strlen(P), j=0;
	while(i<s1 && j<s2)
	{
		if(j<0 || T[i]==P[j])
		{
			i++;
			j++;
		}
		else 
			j = next[j];
	}
	delete []next;
	return i-j;
}
int main()
{
	char* s1 = new char[NUM*2];
	char* s2 = new char[NUM];
	while(scanf("%s %s", s1, s2)!=EOF)
	{
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		if(n1 != n2)
			printf("NO\n");
		else 
		{
			for(int i=n1; i<2*n1; i++) s1[i] = s1[i-n1];
			n1 *= 2;
			s1[n1] = '\0';
			if(KMP(s1, s2)<=(n1-n2))
			{
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}

	return 0;
}
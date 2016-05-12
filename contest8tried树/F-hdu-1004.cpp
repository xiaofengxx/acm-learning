#include<cstdio>
#include<stdlib.h>
int flag;
char bb[50],*p;
struct TrieNode{
    int time;
    struct TrieNode *next[26];
}trie;
void start(struct TrieNode *next)
{
    next->time=0;
    for(int i=0;i<26;i++)
        next->next[i]=NULL;
}
void ins_Trie(char *s,struct TrieNode* next)
{
    p=s;
    while(*s!='\0'&&*s!=' ')
    {
        if(next->next[*s-'a']==NULL)
        {
            next->next[*s-'a']=(struct TrieNode*)malloc(sizeof(struct TrieNode));
            start(next->next[*s-'a']);
        }
        next=next->next[*s-'a'];
        next->time++;
        s++;
    }
    if(next->time>flag)
    {
        flag=next->time;
        for(;s-p>=0;s--)
        {
            bb[s-p]=*s;
        }
    }
    return;
}
int main()
{
    char aa[50];
    int tt;
    while(scanf("%d",&tt)&&tt)
    {
        start(&trie);
        flag=0;
        for(;tt>0;tt--)
            {
                scanf("%s",aa);
                ins_Trie(aa,&trie);
            }
        printf("%s\n",bb);
    }
    return 0;
}

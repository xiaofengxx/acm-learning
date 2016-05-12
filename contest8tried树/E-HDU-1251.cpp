#include<cstdio>
#include<stdlib.h>
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
    //while(*s==' ')
     //   s++;
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
    return;
}
int Find_Trie(char *s,struct TrieNode *next)
{
    while(*s!='\0')
    {
        if(next->next[*s-'a']==NULL)
            return 0;
        next=next->next[*s-'a'];
        s++;
    }
    return next->time;
}
int main()
{
    char aa[12];
    start(&trie);
    while(gets(aa)&&aa[0]!='\0')
        ins_Trie(aa,&trie);
    while(scanf("%s",aa)!=EOF)
        printf("%d\n",Find_Trie(aa,&trie));
    return 0;
}

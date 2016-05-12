#include<cstdio>
#include<stdlib.h>
#include<string.h>
char bb[30],aa[30];
struct TrieNode{
    char dc[30];
    struct TrieNode *next[26];
}trie;
void start(struct TrieNode *next)
{
    next->dc[0]='\0';
    for(int i=0;i<26;i++)
        next->next[i]=NULL;
}
void ins_Trie(char *s,struct TrieNode* next)
{
    while(*s!='\0'&&*s!=' ')
    {
        if(next->next[*s-'a']==NULL)
        {
            next->next[*s-'a']=(struct TrieNode*)malloc(sizeof(struct TrieNode));
            start(next->next[*s-'a']);
        }
        next=next->next[*s-'a'];
        s++;
    }
    strcpy(next->dc,bb);
    return;
}
int Find_Trie(char *s,struct TrieNode *next)
{
    while(*s!='\0')
    {
        if(next->next[*s-'a']==NULL)
            {
                printf("eh\n");
                return 0;
            }
        next=next->next[*s-'a'];
        s++;
    }
    if(next->dc[0]=='\0')
        printf("eh\n");
     else
        printf("%s\n",next->dc);
    return 0;
}
int main()
{
    char ss[60];
    start(&trie);
    while(gets(ss)&&ss[0]!='\0')
    {
        sscanf(ss,"%s %s",bb,aa);
        ins_Trie(aa,&trie);
    }
    while(scanf("%s",aa)!=EOF)
        Find_Trie(aa,&trie);
    return 0;
}

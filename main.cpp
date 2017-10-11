//1.给你100000个长度不超过10的单词。对于每一个单词，我们要判断他出没出现过
#include <iostream>
using namespace std;

typedef struct node{
    struct node* next[26];
}trie_node;

trie_node* create_node() {
    trie_node *p  = new trie_node;
    for (int i = 0; i < 26; ++i)
        p->next[i] = NULL;
    return p;
}

void insert_str(char str[], trie_node* head){
    int len1 = strlen(str);
    trie_node *q, *tmp = head;
    for (int i = 0; i < len1; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            q = create_node();
            tmp->next[c] = q;
            tmp = tmp->next[c];
        }
        else
            tmp = tmp->next[c];
    }
}


void search_str(char str[], trie_node* head){
    int len = strlen(str);
    trie_node* tmp = head;
    for (int i = 0; i < len; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            cout <<"not find the string" <<endl;
            return;
        }
        else {
            tmp = tmp->next[c];
        }
    }
    cout <<"find the string" <<endl;
    return;
}

int main()
{
    char s[10];
    trie_node *head = create_node();
    do{
        cin >> s;
        insert_str(s,head);
    } while(getchar() != '\n');
    search_str("ab", head);
    return 0;
}

//2.给定一个单词，查找词库中以这个单词为前缀的所有单词（包括这个单词）
#include <iostream>
using namespace std;

typedef struct node{
    struct node* next[26]; // 指向各个子树的指针
    bool exist;            // 标记该结点处是否构成单词
}trie_node;

trie_node* create_node() {
    trie_node *p  = new trie_node;
    for (int i = 0; i < 26; ++i)
        p->next[i] = NULL;
    p->exist = false;
    return p;
}

void insert_str(char str[], trie_node* head){
    int len1 = strlen(str);
    trie_node *q, *tmp = head;
    for (int i = 0; i < len1; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            q = create_node();
            tmp->next[c] = q;
            tmp = tmp->next[c];
        }
        else
            tmp = tmp->next[c];
    }
    tmp->exist = true;
}

void dfs(string &res, trie_node* tmp){
    if (tmp->exist)
        cout << res << endl;
    for (int i = 0; i < 26; ++i)
    {
        if (tmp->next[i] != NULL)
        {
            char t = 'a' + i;
            string res1 = res;
            res += t;
            dfs(res, tmp->next[i]);
            res = res1;
        }
    }
}

void search_str(char str[], trie_node* head){
    int len = strlen(str);
    trie_node* tmp = head;
    for (int i = 0; i < len; ++i) {
        int c = str[i] - 'a';
        if(!tmp->next[c]) {
            cout <<"not find the string" <<endl;
            return;
        }
        else {
            tmp = tmp->next[c];
        }
    }
    string res = str;
    cout  << "find the string" << endl;
    dfs(res, tmp);
}

int main()
{
    char s[10];
    trie_node *head = create_node();
    do{
        cin >> s;
        insert_str(s,head);
    } while(getchar() != '\n');
    search_str("ab", head);
    return 0;
}

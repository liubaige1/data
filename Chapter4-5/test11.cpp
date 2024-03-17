#include "String.h"
#include <iostream>
using namespace std;

// 串的顺序存储结构
#define MAXSIZE 100 // 串的最大长度
typedef struct {
    char ch[MAXSIZE]; // 每个分量存储一个字符
    int length; // 串的实际长度
} SString;

// 串的堆分配存储结构
typedef struct {
    char* ch; // 指向串的存储空间
    int length; // 串的长度
} HString;

// 串的块链存储结构
typedef struct StringNode {
    char ch[4]; // 每个分量存储一个字符
    struct StringNode* next; // 指向下一个块
} StringNode, *String;

/*
    // 生成一个其值等于chars的串T
    StrAssign(SString& T, SString c);
    // 由串S复制得串T
    StrCopy(SString &T, SString S);
    // 若S为空串，则返回true，否则返回false 
    StrEmpty(&T);
    // 比较S和T的大小
    int StrCompare(SString S, SString T) {
        for (int i = 1; i <= S.length && i <= T.length; i++) {
            if (S.ch[i] != T.ch[i]) {
                return S.ch[i] - T.ch[i];
            }
        }
        return S.length - T.length;
    }
    // 求串的长度
    StrLength(&T);
    // 用Sub返回串S的第pos个字符起长度为len的子串
    SString SubString(SString &Sub, SString S, int pos, int len){
        if (pos+len-1 > S.length) {
            return false;
        }
        for (int i=pos; i<len+pos; i++){
            Sub.ch[i-pos+1] = S.ch[i];
        }
        Sub.length = len;
        return Sub;
    }
    // 用T返回S1和S2连接而成的新串
    StrConcat(&T, S1, S2);
    // 将串S清空
    ClearString(&T);
    // 销毁串S
    DestoryString(&T);
    // 若主串S中存在和串T值相同的子串，则返回它在主串S中第一次出现的位置，否则返回0
    int Index(SString S, SString T) {
        for (int i = 1; i <= S.length - T.length + 1; i++) {
            SString sub;
            SubString(sub, S, i, T.length);
            if (StrCompare(sub, T) == 0) {
                return i;
            }
        }
        return 0;
    }
*/

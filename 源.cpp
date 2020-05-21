
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)；
int wordcount(char* parameter, char* fileName);
int main(int argc, char* argv[]) {
    char parameter[3];
    char filename[30];
    wordcount(argv[1], argv[2]);
    return 0;

}
int wordcount(char* parameter, char* fileName) {
    FILE* fp;
    int Char = 0;  //字符数
    char count;  //暂存字符
    int Word = 0;    //单词数
    bool is0 = false;    //判断上个字符是否为空格和逗号
    if (parameter[1] != 'c' && parameter[1] != 'w')  //判断参数是否正确
    {
        printf("parameter is wrong!");
    }
    if ((fp = fopen(fileName, "rb")) == NULL)    //判断文件能否成功打开
    {
        perror("file is wrong!");
    }
    while ((count = fgetc(fp))!=EOF)        //当文件没有结束

    {
      
        if (count == '\n')            //出现换行，判断是否是单词的结束
        {
            if (is0 == false)
              Word++;                  //防止漏掉行末单词
            is0 = true;
        }
        else if (count == ' ' || count == ',')
        {
            if (is0 == false)                      //如果前一个字符为空格或者，下一个空格或，不算入单词数
            {
               Word++;
            }
            is0 = true;
        }
        else
        {
            is0 = false;

        }
        Char++;


    } 

    fclose(fp);

    if (is0 == false)
        Word++;             //避免漏掉文段末尾单词
        Word++;             //避免漏掉文段末尾单词

    if (parameter[1] == 'c')          //根据参数判断用户需要的返还值
    {
        printf("char:%d", Char);
    }
    else if (parameter[1] == 'w')
    {
        printf("word:%d", Word);
    }

    return 0;
}
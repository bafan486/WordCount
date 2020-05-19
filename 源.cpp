/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable:4996)；

int wordCount(char* parameters, char* fileName);

int main() {
    char parameters[5];
    char filename[30];
    scanf("%s %s", parameters, filename);
    wordCount(parameters, filename);
    return 0;
}

int wordCount(char* parameters, char* fileName) {  //parameters为控制参数 fileName为读取文件名
    int totalChar = 0;    //总字符数
    int totalWord = 0;    //总单词数
    char buffer[1024];    //缓冲区，存储从文件中读到的内容，这里是以1024（一行）为单位
    int charNum = 0;     //缓冲区中所读内容中的字符数
    int wordNum = 0;     //缓冲区中所读内容中的单词数
    int bufferLen = 0;    //缓存区中存储内容的长度
    int i;        //当前缓存区中第i个字符
    char c;       //读取到的字符
    bool isBlank = false;
    bool isEndOfLine = false;//用于判断上一个字符是否为空格或逗号
    FILE* fp;     //指向文件的指针

    //判断输入的参数是否正确
    if (parameters[0] != 'c' && parameters[0] != 'w') {
        perror("parameters is not correct");
        return -1;
    }

    //判断是否能打开输入的文件
    if ((fp = fopen(fileName, "rb")) == NULL) {
        perror("can't open");
        return -1;
    }

    //以行为单位读取数据并保存到buffer，以供判断
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        bufferLen = strlen(buffer);   //得到读取内容的长度
        for (i = 0; i < bufferLen; i++) {   //遍历缓冲区内容来判断
            c = buffer[i];

            if (c == '\r') {            //判断换行，换行则退出循环
                isEndOfLine = true;
                break;
            }
            //计算单词数
            if (c == ' ' || c == ',') {
                if (!isBlank) {
                    wordNum++;      //如果上一个字符不是空格或逗号，单词数加1
                }
                isBlank = !isBlank;   //将判断是否空格变成true，下一个字符如果为逗号或空格则单词数不加1
            }

            //计算字符数
            charNum++;
            isBlank = false;//字符数加1(因为字符条件包括了所有的字符，此处直接加1，不加判断)
        }

        totalChar += charNum;       //计算一行中字符和单词数
        totalWord += wordNum;

        charNum = 0;
        wordNum = 0;    //一行结束清零
    }
    fclose(fp);
    if (parameters[1] == 'c') {
        printf("char:%d", totalChar);
    }
    else {
        printf("word:%d", totalWord);
    }

    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)；
int wordcount(char* parameter, char* fileName);
int main() {
    char parameter[3];
    char filename[30];
    scanf("%s %s", parameter, filename);
    wordcount(parameter, filename);
    return 0;
}
int wordcount(char* parameter, char* fileName) {
    FILE* fp;
    int Char = 0;  //字符数
    char count;  //暂存字符
    int Word = 0;    //单词数
    char buff[1000];   //存放一行字符
    bool is0 = false;    //判断空格和，
    int g=0;         //记录换行的数组个数

    if (parameter[0]!= 'c' && parameter[0]!= 'w')
    {
        printf("parameter is wrong!");
    }
    if ((fp = fopen(fileName, "rb")) == NULL)
    {
        perror("file is wrong!");
    }
    while (fgets(buff, sizeof(buff), fp) != NULL)
    {
       
        for (int i = 0; i < strlen(buff); i++)
        {
            count = buff[i];
            if (count == '\r') {
                is0 = true;
                break;
            }
        
            if (count == ' ' || count == ',')
            {if (is0 ==false)                      //如果前一个字符为空格或者，下一个空格或，不算入单词数
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
            g = i + 1;
           
        }
      
    } if (is0 == false)
        Word++;                //避免漏掉文段末尾单词
    if (parameter[0] == 'c')
    {
        printf("char:%d", Char);
    }
    else if (parameter[0] == 'w')
    {
        printf("word:%d", Word);
    }
    fclose(fp);
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)；
int wordcount(char* parameter, char* fileName);
int main() {
    char parameter[3];
    char filename[30];
    scanf("%s %s", parameter, filename);
    wordcount(parameter, filename);
    return 0;
}
int wordcount(char* parameter, char* fileName) {
    FILE* fp;
    int Char = 0;  //字符数
    char count;  //暂存字符
    int Word = 0;    //单词数
    bool is0 = false;    //判断空格和，
    if (parameter[1] != 'c' && parameter[1] != 'w')
    {
        printf("parameter is wrong!");
    }
    if ((fp = fopen(fileName, "rb")) == NULL)
    {
        perror("file is wrong!");
    }
    do
    {
        count = fgetc(fp);
        if (count == '\n')
        {
            if (is0 == false)
                Word++;                           //防止漏掉行末单词
            is0 = true;
        }
            if (count == ' ' || count == ',')
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
            

    } while (count != EOF);

    fclose(fp);

    if (is0 == false)
        Word++;                    //避免漏掉文段末尾单词
                   
    if (parameter[1] == 'c')
    {
        printf("char:%d", Char);
    }
    else if (parameter[1] == 'w')
    {
        printf("word:%d", Word);
    }
    
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable:4996)；

int main(int argc, char* argv[]) {       //参数argv[2}表示输入控制参数，argv[3]表示文件名

    int totalChar = 0;      //总字符数
    int totalWord = 0;      //总单词数
    char buffer[1024];      //缓冲区，存储从文件中读到的内容，这里是以1024（一行）为单位
    int charNum = 0;        //缓冲区中所读内容中的字符数
    int wordNum = 0;        //缓冲区中所读内容中的单词数
    int bufferLen = 0;      //缓存区中存储内容的长度
    int i;                  //当前缓存区中第i个字符
    char c;                 //读取到的字符
    bool isBlank = false;
    bool isEndOfLine = false;           //用于判断上一个字符是否为空格或逗号
    FILE* fp;                           //指向文件的指针

    //判断输入的参数是否正确
    if (!(strcmp(argv[2], "-c")) && !(strcmp(argv[2], "-w"))) {
        perror("parameters is not correct!");
        return -1;
    }

    //判断是否能打开输入的文件
    if ((fp = fopen(argv[3], "rb")) == NULL) {
        perror("can't open");
        return -1;
    }

    //以行为单位读取数据并保存到buffer，以供判断
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        bufferLen = strlen(buffer);   //得到读取内容的长度
        for (i = 0; i < bufferLen; i++) {   //遍历缓冲区内容来判断
            c = buffer[i];

            if (c == '\r') {                //判断换行，换行则退出循环
                isEndOfLine = true;
                break;
            }
            //计算单词数
            if (c == ' ' || c == ',') {
                if (!isBlank) {
                    wordNum++;             //如果上一个字符不是空格或逗号，单词数加1
                }
                isBlank = !isBlank;        //将判断是否空格变成true，下一个字符如果为逗号或空格则单词数不加1
            }

            //计算字符数
            charNum++;
            isBlank = false;              //字符数加1(因为字符条件包括了所有的字符，此处直接加1，不加判断)
        }

        totalChar += charNum;             //计算一行中字符和单词数
        totalWord += wordNum;

        charNum = 0;
        wordNum = 0;                      //一行结束清零
    }

    if (c != ' ' && c != ',') {
        totalWord += 1;                     //此处加1，因为最后一个单词如果后面没有空格或逗号会导致单词数少一
    }

    fclose(fp);

    if (!(strcmp(argv[2], "-c"))) {
        printf("字符数:%d", totalChar);
    }
    else {
        printf("单词数:%d", totalWord);
    }

    return 0;
}*/
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
    bool is0 = false;    //判断空格和，
    if (parameter[1] != 'c' && parameter[1] != 'w')
    {
        printf("parameter is wrong!");
    }
    if ((fp = fopen(fileName, "rb")) == NULL)
    {
        perror("file is wrong!");
    }
    while ((count = fgetc(fp))!=EOF)

    {
      
        if (count == '\n')
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

    if (parameter[1] == 'c')
    {
        printf("char:%d", Char);
    }
    else if (parameter[1] == 'w')
    {
        printf("word:%d", Word);
    }

    return 0;
}
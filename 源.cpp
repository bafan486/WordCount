
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)��
int wordcount(char* parameter, char* fileName);
int main(int argc, char* argv[]) {
    char parameter[3];
    char filename[30];
    wordcount(argv[1], argv[2]);
    return 0;

}
int wordcount(char* parameter, char* fileName) {
    FILE* fp;
    int Char = 0;  //�ַ���
    char count;  //�ݴ��ַ�
    int Word = 0;    //������
    bool is0 = false;    //�ж��ϸ��ַ��Ƿ�Ϊ�ո�Ͷ���
    if (parameter[1] != 'c' && parameter[1] != 'w')  //�жϲ����Ƿ���ȷ
    {
        printf("parameter is wrong!");
    }
    if ((fp = fopen(fileName, "rb")) == NULL)    //�ж��ļ��ܷ�ɹ���
    {
        perror("file is wrong!");
    }
    while ((count = fgetc(fp))!=EOF)        //���ļ�û�н���

    {
      
        if (count == '\n')            //���ֻ��У��ж��Ƿ��ǵ��ʵĽ���
        {
            if (is0 == false)
              Word++;                  //��ֹ©����ĩ����
            is0 = true;
        }
        else if (count == ' ' || count == ',')
        {
            if (is0 == false)                      //���ǰһ���ַ�Ϊ�ո���ߣ���һ���ո�򣬲����뵥����
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
        Word++;             //����©���Ķ�ĩβ����
        Word++;             //����©���Ķ�ĩβ����

    if (parameter[1] == 'c')          //���ݲ����ж��û���Ҫ�ķ���ֵ
    {
        printf("char:%d", Char);
    }
    else if (parameter[1] == 'w')
    {
        printf("word:%d", Word);
    }

    return 0;
}
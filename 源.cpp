/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable:4996)��

int wordCount(char* parameters, char* fileName);

int main() {
    char parameters[5];
    char filename[30];
    scanf("%s %s", parameters, filename);
    wordCount(parameters, filename);
    return 0;
}

int wordCount(char* parameters, char* fileName) {  //parametersΪ���Ʋ��� fileNameΪ��ȡ�ļ���
    int totalChar = 0;    //���ַ���
    int totalWord = 0;    //�ܵ�����
    char buffer[1024];    //���������洢���ļ��ж��������ݣ���������1024��һ�У�Ϊ��λ
    int charNum = 0;     //�����������������е��ַ���
    int wordNum = 0;     //�����������������еĵ�����
    int bufferLen = 0;    //�������д洢���ݵĳ���
    int i;        //��ǰ�������е�i���ַ�
    char c;       //��ȡ�����ַ�
    bool isBlank = false;
    bool isEndOfLine = false;//�����ж���һ���ַ��Ƿ�Ϊ�ո�򶺺�
    FILE* fp;     //ָ���ļ���ָ��

    //�ж�����Ĳ����Ƿ���ȷ
    if (parameters[0] != 'c' && parameters[0] != 'w') {
        perror("parameters is not correct");
        return -1;
    }

    //�ж��Ƿ��ܴ�������ļ�
    if ((fp = fopen(fileName, "rb")) == NULL) {
        perror("can't open");
        return -1;
    }

    //����Ϊ��λ��ȡ���ݲ����浽buffer���Թ��ж�
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        bufferLen = strlen(buffer);   //�õ���ȡ���ݵĳ���
        for (i = 0; i < bufferLen; i++) {   //�����������������ж�
            c = buffer[i];

            if (c == '\r') {            //�жϻ��У��������˳�ѭ��
                isEndOfLine = true;
                break;
            }
            //���㵥����
            if (c == ' ' || c == ',') {
                if (!isBlank) {
                    wordNum++;      //�����һ���ַ����ǿո�򶺺ţ���������1
                }
                isBlank = !isBlank;   //���ж��Ƿ�ո���true����һ���ַ����Ϊ���Ż�ո��򵥴�������1
            }

            //�����ַ���
            charNum++;
            isBlank = false;//�ַ�����1(��Ϊ�ַ��������������е��ַ����˴�ֱ�Ӽ�1�������ж�)
        }

        totalChar += charNum;       //����һ�����ַ��͵�����
        totalWord += wordNum;

        charNum = 0;
        wordNum = 0;    //һ�н�������
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
#pragma warning(disable:4996)��
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
    int Char = 0;  //�ַ���
    char count;  //�ݴ��ַ�
    int Word = 0;    //������
    char buff[1000];   //���һ���ַ�
    bool is0 = false;    //�жϿո�ͣ�
    int g=0;         //��¼���е��������

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
            {if (is0 ==false)                      //���ǰһ���ַ�Ϊ�ո���ߣ���һ���ո�򣬲����뵥����
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
        Word++;                //����©���Ķ�ĩβ����
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
#pragma warning(disable:4996)��
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
    int Char = 0;  //�ַ���
    char count;  //�ݴ��ַ�
    int Word = 0;    //������
    bool is0 = false;    //�жϿո�ͣ�
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
                Word++;                           //��ֹ©����ĩ����
            is0 = true;
        }
            if (count == ' ' || count == ',')
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
            

    } while (count != EOF);

    fclose(fp);

    if (is0 == false)
        Word++;                    //����©���Ķ�ĩβ����
                   
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
#pragma warning(disable:4996)��

int main(int argc, char* argv[]) {       //����argv[2}��ʾ������Ʋ�����argv[3]��ʾ�ļ���

    int totalChar = 0;      //���ַ���
    int totalWord = 0;      //�ܵ�����
    char buffer[1024];      //���������洢���ļ��ж��������ݣ���������1024��һ�У�Ϊ��λ
    int charNum = 0;        //�����������������е��ַ���
    int wordNum = 0;        //�����������������еĵ�����
    int bufferLen = 0;      //�������д洢���ݵĳ���
    int i;                  //��ǰ�������е�i���ַ�
    char c;                 //��ȡ�����ַ�
    bool isBlank = false;
    bool isEndOfLine = false;           //�����ж���һ���ַ��Ƿ�Ϊ�ո�򶺺�
    FILE* fp;                           //ָ���ļ���ָ��

    //�ж�����Ĳ����Ƿ���ȷ
    if (!(strcmp(argv[2], "-c")) && !(strcmp(argv[2], "-w"))) {
        perror("parameters is not correct!");
        return -1;
    }

    //�ж��Ƿ��ܴ�������ļ�
    if ((fp = fopen(argv[3], "rb")) == NULL) {
        perror("can't open");
        return -1;
    }

    //����Ϊ��λ��ȡ���ݲ����浽buffer���Թ��ж�
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        bufferLen = strlen(buffer);   //�õ���ȡ���ݵĳ���
        for (i = 0; i < bufferLen; i++) {   //�����������������ж�
            c = buffer[i];

            if (c == '\r') {                //�жϻ��У��������˳�ѭ��
                isEndOfLine = true;
                break;
            }
            //���㵥����
            if (c == ' ' || c == ',') {
                if (!isBlank) {
                    wordNum++;             //�����һ���ַ����ǿո�򶺺ţ���������1
                }
                isBlank = !isBlank;        //���ж��Ƿ�ո���true����һ���ַ����Ϊ���Ż�ո��򵥴�������1
            }

            //�����ַ���
            charNum++;
            isBlank = false;              //�ַ�����1(��Ϊ�ַ��������������е��ַ����˴�ֱ�Ӽ�1�������ж�)
        }

        totalChar += charNum;             //����һ�����ַ��͵�����
        totalWord += wordNum;

        charNum = 0;
        wordNum = 0;                      //һ�н�������
    }

    if (c != ' ' && c != ',') {
        totalWord += 1;                     //�˴���1����Ϊ���һ�������������û�пո�򶺺Żᵼ�µ�������һ
    }

    fclose(fp);

    if (!(strcmp(argv[2], "-c"))) {
        printf("�ַ���:%d", totalChar);
    }
    else {
        printf("������:%d", totalWord);
    }

    return 0;
}*/
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
    bool is0 = false;    //�жϿո�ͣ�
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
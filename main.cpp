#include<stdio.h>
#include<string.h>
void reverse_content (FILE *file)
{
    char s[100];
    if(fgets(s, sizeof(s), file) == NULL)
    {
        return;
    }
    else
    {
        reverse_content(file);
        printf("%s",s);
    }

}

int main()
{
    FILE *file;
    char s[100];
    file = fopen("liki.txt", "a");
    if(file==NULL)
    {
        puts("cannot open file");
    }
    else
    {
        printf("Enter the content:\n");
        while (strlen(gets(s))>0)
        {
            fputs (s,file);
            fputs("\n",file);
        }
        fclose (file);
    }
    printf("contents are being read now\n");
    file = fopen("liki.txt","r");
    if(file == NULL)
    {
        puts("cannot open the file");
    }
    else
    {
        while(fgets(s, sizeof(s), file)!=NULL)
        {
            printf("%s",s);
        }
        fclose(file);
    }
    printf("reversed content:\n");
    file = fopen("liki.txt","r");
    if(file == NULL)
    {
        puts("cannot open file");

    }
    else
    {
        reverse_content(file);
        fclose(file);
    }
    return 0;
}

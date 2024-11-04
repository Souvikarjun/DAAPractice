#include<stdio.h>
#include<string.h>

struct Char
{
    char Alpha;
    int hash;
};

struct Char Alphabate[26];


void StoringChar(char pattern[], char text[]){

    int len_pat = strlen(pattern);
    int len_text = strlen(text);
    int Hash_code = 256;
    int hash_pattern = 0;
    int hash_text = 0;
    int match = 0;
    int alphabates = 26;

    for(int i = 0; i < alphabates; i++){
        Alphabate[i].Alpha = 97+i;
        Alphabate[i].hash = (Alphabate[i].Alpha^2)*Hash_code;
        // printf("%c = %d  ", Alphabate[i].Alpha, Alphabate[i].hash);
    }

    

    for (int i = 0; i < len_text - len_pat; i++)
    {
        if (pattern[0] == text[i])
        {
            for (int j = 0; j < len_pat; j++)
            {
                for(int k = 0; k < 26; k++)
                {
                    if (Alphabate[k].Alpha == pattern[j] && Alphabate[k].Alpha == text[i])
                    {
                        hash_pattern += (Alphabate[k].hash);
                        hash_text += (Alphabate[k].hash);
                        printf("%c %c %c", Alphabate[k].Alpha, pattern[j], text[i]);
                        printf("%d   %d ", hash_pattern, hash_text);
                    }
                }
            }
            
        }
        else{
            hash_pattern = 0;
            hash_text = 0;
            
        }
        if (hash_pattern == hash_text && hash_pattern!=0)
        {
            printf("match at %d index %d  %d", i, hash_pattern, hash_text);
            match = 1;
            break;
        }

    }
    if (match == 0)
    {
        printf("match not found");
    }
     
}

int main(){
    char text[] = "aaabccdd";
    char pattern[] = "aab";

    StoringChar(pattern, text);

    return 0;
}
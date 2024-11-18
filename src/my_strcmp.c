/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    int res = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }
    res = s1[i] - s2[i];
    return res;
}

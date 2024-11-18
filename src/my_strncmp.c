/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    int res = 0;

    while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }
    res = s1[i] - s2[i];
    return res;
}

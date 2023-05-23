#include "mon_shel.h"
/**
 * main - function shell
 * @argc: argument 1
 * @argv: argument 2
 * by wafa & simo
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
int i;
char *prompt = ":) ", *offert = NULL, *args[MAX_ARGS], *path = getenv("PATH");
char *ande_pathe, *pttr;
char **dyro = split_path(path);
ssize_t bit_reading;
size_t buffer_lnth = 0;
while (1)
{
if (isatty(0))
printf("%s", prompt);
bit_reading = getline(&offert, &buffer_lnth, stdin);
if (bit_reading == -1)
{
if (isatty(0))
_putchar(10);
break;
}
if (offert[bit_reading - 1] == '\n')
offert[bit_reading - 1] = '\0';
i = 0;
pttr = strtok(offert, " \t");
while (pttr != NULL && i < MAX_ARGS - 1)
{
args[i] = pttr;
pttr = strtok(NULL, " \t");
i++;
}
args[i] = NULL;
if (args[0] != 0)
{

ande_pathe = detect_find(args[0], dyro);
ecut_com(ande_pathe, args, argv);
}
}
free(offert);
free(dyro);
return (0);
}

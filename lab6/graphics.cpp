#include <graphics.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* itoa(int num, char* str)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    if (isNegative)
        str[i++] = '-';
    str[i] = '\0';

    reverse(str, i);

    return str;
}

void drawCoordinatePlane()
{
    initwindow(WIDTH, HEIGHT);
    line(0, HEIGHT / 2, WIDTH, HEIGHT / 2);
    line(WIDTH / 2, 0, WIDTH / 2, HEIGHT);

    int count = 1;
    for (int i = 30; i < WIDTH; i += 30)
    {
        char str[100];
        line(i + WIDTH / 2, HEIGHT / 2 + 5, i + WIDTH / 2, HEIGHT / 2 - 5);
        outtextxy(i + WIDTH / 2 - 4, HEIGHT / 2 + 10, itoa(count, str));

        line(-i + WIDTH / 2, HEIGHT / 2 + 5, -i + WIDTH / 2, HEIGHT / 2 - 5);
        outtextxy(-i + WIDTH / 2 - 6, HEIGHT / 2 + 10, itoa(-count, str));

        line(WIDTH / 2 + 5, i + HEIGHT / 2, WIDTH / 2 - 5, i + HEIGHT / 2);
        outtextxy(WIDTH / 2 + 10, i + HEIGHT / 2 - 6, itoa(-count, str));

        line(WIDTH / 2 + 5, -i + HEIGHT / 2, WIDTH / 2 - 5, -i + HEIGHT / 2);
        outtextxy(WIDTH / 2 + 10, -i + HEIGHT / 2 - 6, itoa(count, str));
        count++;
    }
}
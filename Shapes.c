#include <stdio.h>

//DrawLine
void DrawLine()
{
    for (int i = 1; i < 5; i++)
    {
        printf("* ");
    }
}

//StripedLine
void DrawStripedLine()
{
    for (int col = 0; col < 3; col++)
    {
        printf("*");
        if (col < 2)
        {
            printf("_");
        }
    }
}

//Square
void DrawSquare()
{
    for (int row = 1; row < 6; row++)
    {
        for (int col = 1; col < 6; col++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

//Parallelogram
void DrawParallelogram(int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            printf("_");
        }

        for (int j = 0; j < number; j++)
        {
            printf("*");
        }

        for (int j = 0; j < i; j++)
        {
            printf("_");
        }
        printf("\n");
    }
}

//Triangle
void DrawTriangle()
{
    int rows = 5;
    for (int col = 0; col < rows; col++)
    {
        for (int star = 0; star < col + 1; star++)
        {
            printf("*");
        }
        for (int i = 0; i < rows - (col + 1); i++)
        {
            printf("_");
        }
        printf("\n");
    }
}

//ReverseTriangle
void DrawReverseTriangle()
{
    int rows = 5;
    for (int col = rows; col > 0; col--)
    {
        for (int star = 0; star < col; star++)
        {
            printf("*");
        }
        for (int i = 0; i < rows - col; i++)
        {
            printf("_");
        }
        printf("\n");
    }
}

//IsocelesTriangle
void DrawIsocelesTriangle()
{
    int rows, k = 0;

    for (int col = 1; col <= 3; col++)
    {
        for (int space = 1; space <= 3 - col; space++)
        {
            printf("_");
        }
        for (int j = 1; j <= 2 * col - 1; j++)
        {
            printf("*");
        }
        for (int space = 1; space <= 3 - col; space++)
        {
            printf("_");
        }
        printf("\n");
    }
}

//ReverseIsocelesTriangle
void DrawReverseIsocelesTriangle(int number)
{
    int h = (number + 1) / 2;
    for (int i = h; i >= 1; i--)
    {
        for (int s = 0; s < h - i; s++)
            printf("_");

        for (int j = 0; j < 2 * i - 1; j++)
            printf("*");

        for (int s = 0; s < h - i; s++)
            printf("_");
        printf("\n");
    }
}

//HourGlass
void DrawHourGlass()
{
    for (int i = 3; i >= 1; i--)
    {
        for (int space = 1; space <= 3 - i; space++)
        {
            printf("_");
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        for (int space = 1; space <= 3 - i; space++)
        {
            printf("_");
        }
        printf("\n");
    }
    for (int i = 2; i <= 3; i++)
    {
        for (int space = 1; space <= 3 - i; space++)
        {
            printf("_");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        for (int space = 1; space <= 3 - i; space++)
        {
            printf("_");
        }
        printf("\n");
    }
}

//Diamond
void DrawDiamond(int size)
{
    {
        int sizeHalf = size / 2;

        for (int i = 0; i <= sizeHalf; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= sizeHalf - i && j <= sizeHalf + i)
                    printf("*");
                else
                    printf("_");
            }
            printf("\n");
        }
        for (int i = sizeHalf - 1; i >= 0; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= sizeHalf - i && j <= sizeHalf + i)
                    printf("*");
                else
                    printf("_");
            }
            printf("\n");
        }
    }
}

//Zero
void DrawZero(int size)
{
    if (size < 3)
    {
        printf("Size must be at least 3. \n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                printf("*");
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");
    }
}

//ArrowUp
void DrawArrowUp(int size)
{
    int sizeHalf = size / 2;

    for (int i = 0; i <= sizeHalf; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= sizeHalf - i && j <= sizeHalf + i)
                printf("*");
            else
                printf("_");
        }
        printf("\n");
    }

    for (int i = 0; i < sizeHalf; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= sizeHalf - 1 && j <= sizeHalf + 1)
                printf("*");
            else
                printf("_");
        }
        printf("\n");
    }
}

//ArrowDown
void DrawArrowDown(int size)
{
    int sizeHalf = size / 2;

    for (int i = 0; i < sizeHalf; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= sizeHalf - 1 && j <= sizeHalf + 1)
                printf("*");
            else
                printf("_");
        }
        printf("\n");
    }
    for (int i = sizeHalf; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= sizeHalf - i && j <= sizeHalf + i)
                printf("*");
            else
                printf("_");
        }
        printf("\n");
    }
}

//DrawX
void DrawX(int size)
{
    if (size < 3)
    {
        printf("Size must be atleast 3. \n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j || i + j == size - 1)
            {
                printf("*");
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");
    }
}

//BowTie
void DrawBowTie(int size)
{
    {
        int sizeHalf = size / 2;

        for (int i = sizeHalf - 1; i >= -1; i--)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= sizeHalf - i && j <= sizeHalf + i)
                    printf("_");
                else
                    printf("*");
            }
            printf("\n");
        }
        for (int i = 0; i <= sizeHalf - 1; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= sizeHalf - i && j <= sizeHalf + i)
                    printf("_");
                else
                    printf("*");
            }
            printf("\n");
        }
    }
}

int main()
{
    int size = 5;
    int number = 5;

    printf("1. Line:\n\n");
    DrawLine();

    printf("\n\n2. Striped Line:\n\n");
    DrawStripedLine();

    printf("\n\n3. Square:\n\n");
    DrawSquare();

    printf("\n\n4. Parallelogram:\n\n");
    DrawParallelogram(number);

    printf("\n5. Triangle:\n\n");
    DrawTriangle();

    printf("\n6. Reverse Triangle:\n\n");
    DrawReverseTriangle();

    printf("\n7. Isoceles Triangle:\n\n");
    DrawIsocelesTriangle();

    printf("\n8. reverseIsocelesTriangle:\n\n");
    DrawReverseIsocelesTriangle(number);

    printf("\n9. Hour Glass:\n\n");
    DrawHourGlass();

    printf("\n10. Diamond:\n\n");
    DrawDiamond(number);

    printf("\n11. Zero:\n\n");
    DrawZero(size);

    printf("\n12. Arrow Up:\n\n");
    DrawArrowUp(size);

    printf("\n13. Arrow Down:\n\n");
    DrawArrowDown(size);

    printf("\n14. X:\n\n");
    DrawX(size);

    printf("\n15. Bow Tie:\n\n");
    DrawBowTie(size);

    return 0;
}

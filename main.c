#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

// drawing gets messed up when this gets into double digits
int SIZE = 9;

int main()
{
    bool running = true;

    int i_player = 1;

    int i_row;
    int i_column;

    int m[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            m[i][j] = 0;
    }
    
    while(running)
    {
        // draw the coordinate on top
        printf(" ");
        for(int i = 0; i < SIZE; i++)
        {
            printf(" %d", i + 1);
        }
        printf("\n");

        // draw board
        for(int i = 0; i < SIZE; i++)
        {
            char c;
            
            printf("%d ", i + 1);

            for(int j = 0; j < SIZE; j++)
            {
                if(m[i][j] == 0)
                    c = '+';
                if(m[i][j] == 1)
                    c = 'O';
                if(m[i][j] == 2)
                    c = 'X';

                printf("%c ", c);
            }

            printf("\n");
        }
        
        // input
        printf("Player %d\n", i_player);

        printf("Row: ");
        scanf(" %d", &i_row);

        printf("Column: ");
        scanf(" %d", &i_column);

        i_column--; i_row--;

        m[i_row][i_column] = i_player;

        // count liberties of pieces
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(m[i][j] != 0)
                {
                    int i_libs = 4;

                    if (m[i][j] == 1)
                    {
                        if(i > 0)
                        {
                            if(m[i - 1][j] == 2)
                                i_libs--;
                        }  

                        if(j > 0)
                        {  
                            if(m[i][j - 1] == 2)
                                i_libs--;
                        }

                        if(m[i + 1][j] == 2)
                            i_libs--;
                        if(m[i][j + 1] == 2)
                            i_libs--;

                        if(i < 1)
                            i_libs--;
                        if(j < 1)
                            i_libs--;
                    }

                    if (m[i][j] == 2)
                    {
                        if(i > 0)
                        {
                            if(m[i - 1][j] == 1)
                                i_libs--;
                        }  

                        if(j > 0)
                        {  
                            if(m[i][j - 1] == 1)
                                i_libs--;
                        }

                        if(m[i + 1][j] == 1)
                            i_libs--;
                        if(m[i][j + 1] == 1)
                            i_libs--;

                        if(i < 1)
                            i_libs--;
                        if(j < 1)
                            i_libs--;
                    }

                    if(i_libs == 0)
                            m[i][j] = 0;
                }
            }
        }

        if(i_player == 1)
            i_player = 2;
        else
            i_player = 1;
    }
}

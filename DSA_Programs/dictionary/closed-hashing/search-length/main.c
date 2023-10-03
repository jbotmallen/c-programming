    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define MAX 10
    #define EMPTY '!'
    #define DELETED '~'

    typedef char DICTIONARY[MAX];

    void init(DICTIONARY D)
    {
        int x;

        for(x = 0; x < MAX; x++)
        D[x] = EMPTY;
    }

    void insert(DICTIONARY D, char elem, int idx)
    {
        int x;

        for(x = idx; D[x] != EMPTY && D[x] != DELETED && D[x] != elem; x = (x + 1) % MAX) {}

        if(D[x] == EMPTY || D[x] == DELETED) D[x] = elem;
    }

    void populateList(DICTIONARY D)
    {
        DICTIONARY set = { "ABCDEFGH" };
        int setValues[8] = { 1, 4, 9, 9, 0, 3, 4, 3}, x;

        for(x = 0; x < 8; x++) {
            insert(D, set[x], setValues[x]);
        }
    }

    int getSearchLength(DICTIONARY D)
    {
        int ret = 0, setValues[8] = { 1, 4, 9, 9, 0, 3, 4, 3}, x, y, ctr;
        DICTIONARY set = { "ABCDEFGH" };

        for(x = 0; x < 8; x++) {
            for(y = setValues[x], ctr = 1; D[y] != set[x] && D[y] != EMPTY; y = (y + 1) % MAX, ctr++) {}
            ret += ctr;
        }
    }

    int main()
    {
        DICTIONARY d;

        init(d);
        populateList(d);

        return 0;
    }
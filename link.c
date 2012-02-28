#include <stdio.h>
#include <stdlib.h>

typedef struct s{
        int id;
        struct s *next;
}people_t;

void create(people_t *head, int m)
{
        int i = 1;
        people_t *bak = head;
        m--;
        while(m--)
        {
                head->next = (people_t *)malloc(sizeof(people_t));
                head->next->id = ++i;
                head = head->next;
        }
        head->next = bak;
}

void josephus(people_t *head, int m, int n)
{
        int cnt = 0;
        while(m)
        {
                if(head->id)
                {
                        cnt++;
                        if(cnt == n)
                        {
                                m--;
                                printf("%d out\n", head->id);
                                head->id = 0;
                                cnt = 0;
                        }
                }
                head = head->next;
        }
}

int main(int argc, const char *argv[])
{
        people_t head;
        head.id = 1;
        create(&head, 10);
        josephus(&head, 10, 3);
        return 0;
}

//PROTECTING HEADER FILE
#ifndef request_h
#define request_h

#define ROOM_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 15

struct request{
        char classroom[ROOM_LEN];
        char first[NAME_LEN+1];
        char last[NAME_LEN+1];
        char phone[PHONE_LEN+1];;

        struct request *next;
};

struct request *append_to_list(struct request *list);
struct request *delete_from_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);

#endif

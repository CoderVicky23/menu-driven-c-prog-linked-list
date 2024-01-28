struct DOB {
    int date;
    int month;
    int year;
};

struct STUDENT {
    int roll;
    char name[20];
    float marks;
    struct DOB dob;
};

struct NODE {
    struct STUDENT student;
    struct NODE * next;
};
// view all records
void viewList(struct NODE * head) {
    struct NODE * ptr = head;
    int index=1;
    while(ptr) {
        printf("Student %d\n", index);
        printf("Roll No: %d\n", ptr->student.roll);
        printf("Name: %s\n", ptr->student.name);
        printf("Marks: %f\n", ptr->student.marks);
        printf("DOB: %d-%d-%d\n\n", ptr->student.dob.date, ptr->student.dob.month, ptr->student.dob.year);
        ptr = ptr->next;
        index++;
    }
    while ((getchar()) != '\n');
    char c;
    c = getchar();
}

// view single record
void viewSingle(struct NODE * head) {
    struct NODE * ptr = head;
    int roll;
    printf("Enter Roll No. to Display: ");
    scanf("%d", &roll);
    while (ptr) {
        if (roll == ptr->student.roll) {
            printf("Roll No: %d\n", ptr->student.roll);
            printf("Name: %s\n", ptr->student.name);
            printf("Marks: %f\n", ptr->student.marks);
            printf("DOB: %d-%d-%d\n\n", ptr->student.dob.date, ptr->student.dob.month, ptr->student.dob.year);
            break;
        }
        ptr = ptr->next;
    }
    while ((getchar()) != '\n');
    char c;
    c = getchar();
}

// add students
struct NODE * insertNode(struct NODE * head) {
    struct NODE * new = (struct NODE *) malloc(sizeof(struct NODE));
    printf("\n");
    printf("Enter Roll No.   \n");
    scanf("%d", &new->student.roll);
    printf("Enter Name      \n");
    scanf(" %[^\n]s", new->student.name);
    printf("Enter Your Marks    \n");
    scanf("%f", &new->student.marks);
    printf("Enter your DOB(dd-mm-yyyy)  \n");
    scanf("%d %d %d", &new->student.dob.date, &new->student.dob.month, &new->student.dob.year);
    if (new == NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
    new->next = NULL;
    struct NODE * ptr = head;
    if (ptr == NULL) {
        head = new;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

// delete record
struct NODE * deleteStudent(struct NODE * head) {
    int roll;
    printf("Enter Roll Number you want to Delete\n");
    scanf("%d", &roll);
    struct NODE * ptr = head;
    struct NODE * current = NULL;
    if (ptr->student.roll == roll) {
        head = ptr->next;
        free(ptr);
        return head;
    }
    while (ptr->next) {
        if (ptr->student.roll == roll) {
            current->next = ptr->next;
            free(ptr);
            return head;
        }
        current = ptr;
        ptr = ptr->next;
    }
    if (ptr->student.roll == roll) {
        current->next = NULL;
        free(ptr);
    }
    return head;
}

// update record

struct NODE * updateRecord(struct NODE * head) {
    int roll;
    printf("Enter the roll no you want to update\n");
    scanf(" %d", &roll);
    struct NODE * ptr = head;
    while (ptr) {
        if (ptr->student.roll == roll) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", ptr->student.name);
            printf("Enter New Marks: ");
            scanf(" %f", &ptr->student.marks);
            printf("Enter New DOB: ");
            scanf("%d %d %d", &ptr->student.dob.date, &ptr->student.dob.month, &ptr->student.dob.year);
        }
        ptr = ptr->next;
    }
    return head;
}
/* Name    : Osaid Hasan Nur
 * ID      : 1210733
 * Section : 1
 * Instructor : Ahmad Abusnaina
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node* Node ;
// Function prototype
Node new_Node(Node);
void insert_First(int, Node);
void insert_Pos(int ,Node , Node);
void insert_Last(int , Node );
int isLast(Node , Node);
int isEmpty(Node);
Node findPrevious(int ,Node ) ;
Node find(int , Node);
void deleteList(Node) ;
void delete(int , Node);
void deleteFirst(Node ) ;
int size(Node) ;
int isBiggerThan(Node , Node );
void fprint_List(Node);
void print_List(Node);
void reverse(Node);
Node complement(Node ) ;
void equalDigits (Node , Node  ) ;
int isLargerThan(Node, Node ) ;
void filter(Node ) ;
Node add(Node , Node,int,int);
Node subtract (Node ,Node,int ,int ) ;
Node multiply(Node , Node ) ;
Node divide(Node , Node,Node ) ;

struct node{
    int data;
    Node next;
    Node prev;
};
FILE * input ;
FILE * output ;
int main() {
    // reading the file named "input" and file named "output" ;
    input = fopen("input.txt","r") ;
    output = fopen("output.txt","w");
    printf(">>>>>>>>>>>> Welcome <<<<<<<<<<<<<\n");

    // create  linked lists for the two numbers , each number in a list
    Node num1 = new_Node(num1) ;
    Node num2 = new_Node(num2) ;
    char c = 'a' ;

    // This count to number the numbers in the input file and show it in the terminal
    int count = 1 ;
    printf("%d)",count) ;

    // printing the content of the file
    while((c = fgetc(input)) != EOF) {
        if(c == '\n' || c == ' ') {
            printf("\n%d)",++count);
            continue;
        }
        printf("%c",c);
    }
    printf("\n");

    // choosing the two numbers that the user wants to do operation on
    printf("Choose two numbers A and B respectively : >>> ") ;
    int n1 = 0,n2=0 ;
    scanf("%d%d",&n1,&n2) ;
    //This is for invalid input , the program will continue if and only if the user
    // entered valid number
    while(n1>count || n2>count){
        printf("Invalid input ! try again \n") ;
        scanf("%d%d",&n1,&n2) ;
    }
    /* My algorithm to read the two desired numbers from the file is little strange , I depends on the
     * entered index number from the user , for example , if he choose the 3rd number , that means I
     * don't want the first two numbers in the file , in other words , I have to make skip on two numbers
     * with two spaces , one after the first numbers , and the other after the second number , so I make
     * n1-- and n2-- , if i need the 3rd number , I skip  two spaces ..etc , to do this algorithm , i need
     * to open the file again to begin from the first character ( this is how fgetc function work )
     */
    n1-- ;
    n2-- ;
    // these are counters for the number of spaces have read
    int c1 = 0 , c2 = 0 ;
    input = fopen("input.txt","r") ;
    while ((c = fgetc(input)) != EOF){
        if(c == ' ' || c=='\n')c1++ ;
        if(c1==n1){
            if(c != ' ' && c!='\n')insert_Last(c-'0',num1) ;
        }
        else if(c1>n1) break ;
    }
    input = fopen("input.txt","r") ;
    while ((c = fgetc(input)) != EOF){
        if(c == ' ' || c=='\n')c2++ ;
        if(c2==n2){
            if(c != ' ' && c!='\n')insert_Last(c-'0',num2) ;
        }
        else if(c2>n2) break ;
    }

    printf("You choosed >>>  A = ") ;
    print_List(num1) ;
    printf("            >>>  B = ");
    print_List(num2);

    // The Selection Menu
    while(1) {
        int choice=0 ;
        printf("choose the operation (1-5): \n");
        printf("1- Add ( A + B )\n");
        printf("2- Subtract ( A - B )\n");
        printf("3- Multiply ( A * B )  \n");
        printf("4- Divide ( A / B )\n");
        printf("5- Choose another numbers\n");
        printf("6- Exit \n");
        scanf("%d",&choice);

        // Addition :
        if (choice == 1 ){
            Node ans = add(num1,num2,-1,-1);
            filter(ans);
            fprintf(output,"Sum = ");
            fprint_List(ans) ;
            printf("Addition operation done , check the file!\n");
        }

        // Subtraction :
        else if (choice == 2 ){
            Node ans = subtract(num1,num2,-1,-1) ;
            filter(ans);
            fprintf(output,"Sub = ");
            fprint_List(ans) ;
            printf("Subtraction operation done , check the file!\n");
        }
        // Multiplying :
        else if (choice == 3 ){
            Node ans = multiply(num1,num2);
            filter(ans);
            fprintf(output,"Mul = ");
            fprint_List(ans);
            printf("Multiplying operation done , check the file!\n");
        }

        // Division :
        else if (choice == 4 ){
            Node remainder = new_Node(remainder);
            Node ans = divide(num1,num2,remainder) ;
            filter(ans);
            filter(remainder);
            fprintf(output,"Quotient : ");
            fprint_List(ans) ;
            fprintf(output,"Remainder : ");
            fprint_List(remainder);
            printf("Division operation done , check the file!\n");
        }

        // Choosing another values of A and B :
        else if (choice == 5){
            // delete the previous lists to store different values of A and B in it
            deleteList(num1);
            deleteList(num2) ;
            printf("Choose two numbers A and B respectively : >>> ") ;
            scanf("%d%d",&n1,&n2) ;
            n1-- ;
            n2-- ;
            // these are counters for the number of spaces have read
             c1 = 0 , c2 = 0 ;
            input = fopen("input.txt","r") ;
            while ((c = fgetc(input)) != EOF){
                if(c == ' ' || c=='\n')c1++ ;
                if(c1==n1){
                    if(c != ' ' && c!='\n')insert_Last(c-'0',num1) ;
                }
                else if(c1>n1) break ;
            }
            input = fopen("input.txt","r") ;
            while ((c = fgetc(input)) != EOF){
                if(c == ' ' || c=='\n')c2++ ;
                if(c2==n2){
                    if(c != ' ' && c!='\n')insert_Last(c-'0',num2) ;
                }
                else if(c2>n2) break ;
            }
            printf("You choosed >>>  A = ") ;
            print_List(num1) ;
            printf("            >>>  B = ");
            print_List(num2);
        }

        // Exit
        else if (choice == 6 ){
            printf("********** Thank you for using My Program  ************ \n") ;
            printf("-------------------- Good By -------------------------");
            break ;
        }
        else printf("Invalid Input ! try again \n") ;
    }
    fclose(input) ;
    fclose(output) ;
    return 0;
}

// Function to make a new node
Node new_Node(Node L){
    L = (Node)malloc(sizeof(struct node));
    L->data = 0 ;
    L->next = NULL;
    L->prev = NULL;
    return L;
}

// Insert nodes at the first of the linked list
void insert_First(int x, Node L){
    Node newNode = new_Node(newNode);
    newNode->data = x ;
    newNode->next = L->next;
    newNode->prev = L;
    L->next = newNode;
    L->next->prev = newNode;
}

// Insert nodes at specific loacation
void insert_Pos(int x,Node P, Node L){
    Node newNode = new_Node(newNode);
    newNode->data = x;
    newNode->next = P->next;
    newNode->prev = P;
    P->next->prev = newNode;
    P->next = newNode;
}

// Insert nodes at the last of the linked list
void insert_Last(int x , Node L){
    Node newNode = new_Node(newNode);
    newNode->data = x ;
    Node lst = L ;
    while (lst->next!=NULL){
        lst = lst->next ;
    }
    lst->next = newNode ;
    newNode->prev = lst ;
    newNode->next = NULL ;
}

// To check if the node p is the last node in linked list L
int isLast(Node P , Node L){
    return P->next == NULL ;
}

// To check if the list is empty
int isEmpty(Node L){
    return L->next == NULL && L->prev==NULL ;
}

// Delete the linked list and free all nodes except the head
void deleteList(Node L){
    Node p , temp ;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        temp= p->next ;
        free(p) ;
        p = temp ;
    }
}

// To delete nodes with specific data value
void delete(int x, Node L){
    Node temp = findPrevious(x,L);
    if(!isLast(temp,L)){
        Node temp2= temp->next;
        temp2->next->prev = temp;
        temp->next = temp2->next;
        temp2->prev = NULL;
        temp2->next = NULL;
        free(temp2);
    }
}

// To delete the first node of the linked list(I used this function to delete the sign of the negative numbers)
void deleteFirst(Node L){
    Node temp = L ;
    if(!isLast(temp->next,L)){
        Node temp2 = temp->next ;
        temp2->next->prev = temp;
        temp->next = temp2->next;
        temp2->prev = NULL;
        temp2->next = NULL;
        free(temp2);
    }
    else {
        Node temp2 = temp->next ;
        temp->next = NULL ;
        free(temp2) ;
    }
}

// To find the previous node of a node containing desired value
Node findPrevious(int x,Node L){
    Node p = L;
    while(p->next->data!=x && p->next!=NULL){
        p = p->next;
    }
    return p;
}

// To find a node with specific data value
Node find(int x, Node L){
    Node p = L->next;
    while(p->data!=x && p!=NULL){
        p = p->next;
    }
    return p;
}

// calculates the size of the linked list ( the number of nodes)
int size(Node L){
    Node p = L->next ;
    int count = 0 ;
    while(p!= NULL){
        count ++ ;
        p=p->next ;
    }
    return count ;
}

// To print the content of the linked list on the file
void fprint_List(Node L){
    Node p = L->next;
    while(p!=NULL){
        fprintf(output,"%c",p->data+'0');
        p = p->next;
    }
    fprintf(output," \n");
}

// To print the content of the linked list on the screen (terminal)
void print_List(Node L){
    Node p = L->next;
    while(p!=NULL){
        printf("%c",p->data+'0');
        p = p->next;
    }
    printf(" \n");
}
//  Reverse the nodes of a linked list
void reverse(Node L){
    Node curr  = L->next;
    Node prev = NULL;
    Node nxt  = curr->next;

    while(curr!=NULL){
        curr->next = prev;
        curr->prev = nxt;
        prev = curr;
        curr = nxt;
        if(nxt!=NULL)
            nxt = nxt->next;
    }
    L->next = prev;
    prev->prev = L;
}

// To compare the size of L1 and L2 , it returns 1 if larger , -1 if smaller , 0 if equal
int isBiggerThan(Node L1 , Node L2) {
    int n1 = size(L1) ;
    int n2 = size(L2) ;
    if(L1->next->data == -3) n1-- ;
    if (L2->next->data == -3) n2-- ;
    return n1 > n2 ;
}

// To compare the two numbers represented in the linked lists ( compare the content of nodes)
int isLargerThan(Node L1, Node L2){
    // compares the magnitude only without the considration of sign
    equalDigits(L1,L2) ;
    Node temp1 = L1 ;
    Node temp2 = L2 ;
    int neg1 = 0 , neg2 = 0 ;
    if(temp1->next->data == -3) {
        neg1 = 1;
        deleteFirst(L1) ;
    }
    if(temp2->next->data == -3){
        neg2 = 1 ;
        deleteFirst(L2);
    }
    while (temp1->next != NULL){
        if(temp1->next->data > temp2->next->data) {
            if(neg1)insert_First(-3,L1) ;
            if(neg2)insert_First(-3,L2) ;
            return 1 ;
        }
        else if (temp1->next->data < temp2->next->data) {
            if(neg1)insert_First(-3,L1) ;
            if(neg2)insert_First(-3,L2) ;
            return -1 ;
        }
        temp1 = temp1->next ;
        temp2 = temp2->next ;
    }
    return  0 ;
}

// Find the 2's complement of the number stored in a linked list , it returns a list
// representing the complement ( I used it to make the subtraction operation )
Node complement(Node L){
    Node p = L ;
    Node comp = new_Node(comp) ;
    if(p->next->data == -3) return L ;
    while(p->next != NULL){
        insert_Last(9 - p->next->data,comp) ;
        p = p->next;
    }
    Node temp = new_Node(temp) ;
    insert_Last(1,temp) ;
    equalDigits(comp,temp) ;
    return add(comp,temp,-1,-1) ; // f1 and f2 are -1 because i don't have previous sign
}

// This function make the two numbers stored in the lists with same number of digits
// by adding zeroes in the left of the number with less number of digits
void equalDigits (Node L1 , Node L2 ){
    int diff =0,flag1 = 0 , flag2=0 ;
    //remove the signs for the numbers and put flags instead
    if(L1->next->data == -3) {
        flag1 =1 ;
        deleteFirst(L1) ;
    }
    if(L2->next->data == -3 ){
        flag2 = 1 ;
        deleteFirst(L2) ;
    }
    // if the size of L1 is more than L2 we need to append zeroes to L2
    if(isBiggerThan(L1,L2)){
        diff = size(L1)- size(L2) ;
        for (int i = 0; i < diff ; ++i) {
            insert_First(0,L2) ;
        }
    }
    // and if the size of L2 is more than L1 we need to append zeroes to L1
    else if(isBiggerThan(L2,L1)){
        diff = size(L2)- size(L1) ;
        for (int i = 0; i < diff; ++i) {
            insert_First(0,L1) ;
        }
    }
    //roll back the signs to L1 and L2
    if(flag1) insert_First(-3,L1);
    if(flag2) insert_First(-3,L2);
}

// Filter the number representing in the linked list by removing the leading zeroes if exists
void filter(Node L){
    // this flag is active if the number is zero , then we don't have to filter it , we need
    // the result as it
    int flag = 0 ;
    int neg =0;
    if(L->next->data == -3) {
        neg = 1;
        deleteFirst(L) ;
    }
    // this if statement to break the function when the list contains the zero as value and no values after it
    while(L ->next != NULL &&L->next->data == 0 && !flag){
        if(L->next->data == 0 && L->next->next == NULL)break;
        deleteFirst(L) ;
    }
    if(neg)insert_First(-3,L) ;
}

// Add two numbers represented in two linked lists (two numbers with their signs )
Node add(Node L1 , Node L2, int f1 , int f2){
    int carry = 0 , both_neg=0 , neg1=0,neg2=0 ;
    equalDigits(L1,L2) ;
    // remove the signs of the numbers and put flags instead
    if(L1->next->data == -3)
    {
        neg1 =1 ;
        deleteFirst(L1) ;
    }
    if(L2->next->data == -3) {
        neg2 = 1;
        deleteFirst(L2) ;
    }
    both_neg = neg1 && neg2 ;
    // if the first number is negative and the second number is positive , then we will subtract
    // the first number from the second number , subtract function is called
    if (neg1 && !neg2) {
        // the arguments neg2 , neg1 means that the function stubtract will consider the signs of L1 and L2 after
        // make the operation using them , this method is to protect the signs of L1 and L2 to use them in
        // other operations
        return subtract(L2, L1,neg2,neg1);
    }
    // if the second number is negative and the first number is positive , then we will subtract
    // the second number form the first number , subtract function is called
    else if (neg2&&!neg1) {
        return subtract(L1, L2,neg1,neg2);
    }
    reverse(L1) ;
    reverse(L2) ;
    Node p1 = L1 , p2=L2 ;
    Node sum = new_Node(sum) ;
    int n = size(L1 );
    // The tecnique i used here is to using the carry integer if the summation of the two digits is more than 9
    for (int i = 0; i < n; ++i) {
        int digit = carry +p1->next->data + p2->next->data ;
        if( digit > 9){
            insert_Last(digit%10,sum) ;
            carry = 1 ;
        }
        else {
            insert_Last(digit,sum);
            carry = 0 ;
        }
        p1 = p1->next ;
        p2 = p2->next;
    }
    // the final carry is added to the sum if exists
    if(carry == 1) insert_Last(1,sum) ;
    reverse(sum) ;
    reverse(L1) ;
    reverse(L2) ;
    // roll back the signs for the numbers
    if(neg1) insert_First(-3, L1);
    if(neg2) insert_First(-3, L2);
    // f1 and f2 are flags that stores the original sign of the numbers before making operations on it
    // if there is contradiction between f1 and neg1 or between f2 and neg2 , we consider the f1 and f2
    // are the correct (the original sign) , so we modify the numbers if needed .
    if(f1==1&&!neg1)insert_First(-3,L1);
    if(f1==0 &&neg1) deleteFirst(L1);
    if(f2==1&&!neg2) insert_First(-3,L2) ;
    if(f2==0 && neg2)deleteFirst(L2) ;
    // if both numbers are negative , the result will be negative too, but if both are positive , the
    // result will be positive
    if(both_neg) {
        insert_First(-3, sum);
    }
    return sum ;
}

// Subtract two numbers represented in two linked lists ( two numbers with their signs )
Node subtract (Node L1,Node L2,int f1, int f2){
    int neg1=0 , neg2 = 0 ;
    equalDigits(L1,L2) ;
    // remove the signs for two numbers and put flags instead
    if(L1->next->data == -3)
    {
        neg1 =1 ;
        deleteFirst(L1) ;
    }
    if(L2->next->data == -3) {
        neg2 = 1;
        deleteFirst(L2) ;
    }
    // if both numbers are negative , the negative sign for the second number will disappear ,
    // we will subtract the first number from the second number
    if(neg1 && neg2){
        return subtract(L2,L1,neg1,neg2) ;
    }
    // if the first number is negative and second number is positive , then we will add their absolue value ,
    // and the result will be negative
    else if (neg1 && !neg2) {
        insert_First(-3,L1) ;
        insert_First(-3,L2) ;
        return add(L1, L2,neg1,neg2);
    }
    // if the first number is positive , and the second number is negative , the negative sign for the second
    // number will disappear , and we will add the absolute values for the two numbers and the result will be positive
    else if (!neg1 && neg2) {
        return add(L1, L2,neg1,neg2);
    }
    // The last case that if both numbers are positive , then we will subtract the second number from the first one
    // , the method i used is to find the complement for the second number and add it to the first one .
    int n = size(L1) ;
    Node temp = add(L1, complement(L2),-1,-1) ;
    // if the final answer has an extra digit ( final carry) , then the carry will be discarded
    if(size(temp) > n){
        deleteFirst(temp) ;
        // roll back the signs for L1 and L2
        if(neg1)insert_First(-3,L1);
        if(neg2)insert_First(-3,L2);
        // f1 and f2 are flags that stores the original sign of the numbers before making operations on it
        // if there is contradiction between f1 and neg1 or between f2 and neg2 , we consider the f1 and f2
        // are the correct (the original sign) , so we modify the numbers if needed .
        if(f1==1&&!neg1)insert_First(-3,L1);
        if(f1==0 &&neg1) deleteFirst(L1);
        if(f2==1&&!neg2) insert_First(-3,L2) ;
        if(f2==0 && neg2)deleteFirst(L2) ;
        return temp ;
    }
    // and if the final answer don't have extra digit( no final carry) , then we take the complement for the result
    // , and it will be with negative sign
    else{
        Node temp2 = complement(temp) ;
        insert_First(-3,temp2) ;
        //roll back the signs for L1 , L2
        if(neg1)insert_First(-3,L1);
        if(neg2)insert_First(-3,L2);
        // f1 and f2 are flags that stores the original sign of the numbers before making operations on it
        // if there is contradiction between f1 and neg1 or between f2 and neg2 , we consider the f1 and f2
        // are the correct (the original sign) , so we modify the numbers if needed .
        if(f1==1&&!neg1)insert_First(-3,L1);
        if(f1==0 &&neg1) deleteFirst(L1);
        if(f2==1&&!neg2) insert_First(-3,L2) ;
        if(f2==0 && neg2)deleteFirst(L2) ;
        return temp2 ;
    }
}

// Multiply two numbers represented in two linked lists ( two numbers with their signs )
Node multiply(Node L1 , Node L2){
    Node ptr1 = L1 , ptr2 =L2 ;
    int neg1 = 0 , neg2=0 ;
    // remove the sign of two numbers and put flags instead
    if (L1->next->data == -3) {
        neg1 = 1 ;
        deleteFirst(L1);
    }
    if (L2->next->data == -3){
        neg2 =  1 ;
        deleteFirst(L2) ;
    }
    reverse(ptr1) ;
    reverse(ptr2) ;
    Node res = new_Node(res) ;
    insert_Last(0,res) ;
    int count = 0 ;
    // Every digit in the first number will be multiplied to all digits in the second number
    // and in every digit , i append a zero to the result
    while(ptr1->next !=NULL){
        ptr2 = L2 ;
        int carry = 0 , carry2 = 0 ;
        Node temp = new_Node(temp) ;
        for (int i = 0; i < count; i++)
        {
            insert_Last(0 ,temp) ;
        }
        count++ ;
        while (ptr2->next != NULL){
            int sum = ptr1->next->data * ptr2->next->data + carry ;
            int digit = sum%10 ;
            insert_Last(digit,temp);
            sum/=10 ;
            carry = sum ;
            ptr2 = ptr2->next;
        }
        if(carry !=0) insert_Last(carry,temp) ;
        reverse(temp) ;
        res = add(res,temp,-1,-1) ;
        deleteList(temp);
        ptr1 = ptr1->next ;
    }
    reverse(L1) ;
    reverse(L2) ;
    // roll back the signs for two numbers
    if(neg1) insert_First(-3,L1);
    if(neg2) insert_First(-3,L2) ;
    // the result will be negative if one of them is negative
    if(neg2&& !neg1 || neg1 && !neg2) insert_First(-3,res) ;
    return res ;
}

// Divide two numbers represented in two linked lists ( two numbers with their signs )
Node divide(Node L1 , Node L2, Node remainder ){
    int digit = 0, neg1 = 0 , neg2 = 0  ;
    // remove the sign for two numbers and put flags instead
    if (L1->next->data == -3) {
        neg1 = 1 ;
        deleteFirst(L1);
    }
    if (L2->next->data == -3){
        neg2 =  1 ;
        deleteFirst(L2) ;
    }
    Node result = new_Node(result);
    insert_First(0,result);
    // The tecnique i used is the repeated subtraction algorithm , the number still being subtracted
    // untill the dividend become less than the divisor , the number of times i repeated this is the result (integer division)
    Node temp1 = L1 ;
    Node temp2 = L2 ;
    Node rem = new_Node(rem) ;
    while (temp1->next!= NULL){
        digit= temp1->next->data ;
        insert_Last(digit, rem) ;
        temp1 = temp1->next ;
        if(isLargerThan(rem, temp2) == -1 ) {
            insert_Last(0,result) ;
            continue;
        }
        int rr = 0 ;
        while(isLargerThan(rem, temp2) == 1 || isLargerThan(rem, temp2)== 0 ){
            rr++ ;
            rem = subtract(rem, temp2, -1, -1) ;
        }
        insert_Last(rr,result) ;
    }
    // roll back the signs for two numbers
    if(neg1) insert_First(-3,L1);
    if(neg2) insert_First(-3,L2) ;
    // if one of them is negative , the answer will be negative
    if(neg2&& !neg1 || neg1 && !neg2) insert_First(-3,result) ;
    remainder->next = rem;
    return result ;
}

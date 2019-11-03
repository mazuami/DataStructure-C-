
/* -- Check if a linked list is Palindrom ---- */
/*---- 1) Find total elements in the linked list ---------*/
/*-----2) Find the middle element ------------------------*/
/*-----3) If total element is an odd number then ----------*/
/*-----4)  then run a loop till the middle element to push the elements to put into a Stack -----*/
/*-----5)  Run a loop for the remaining  elements-----------*/
/*-----6)  pop the elements from the stack and compare the elements with remaining element ------*/
/*-----7)  if the elements are same then return true its palindrom
/*-----8) Else move one element ahead ---------------------*/
/*-----9)  then run a loop till the middle element to push the elements to put into a Stack -----*/
/*-----10)  Run a loop for the remaining  elements-----------*/
/*-----11)  pop the elements from the stack and compare the elements with remaining element ------*/
/*-----12)  if the elements are same then return true its palindrom

#include<stdio.h>
struct Node {
    int data;
    struct Node *next; 
    
};

struct StackNode{
    int data;
    struct StackNode *next;
};

struct StackNode *top=NULL;

void push(int _data){
    struct StackNode *newNode= new StackNode();
    newNode->data=_data;
    newNode->next=top;
    top=newNode;
    
}


struct StackNode* pop(){
    struct StackNode *temp; 
    temp=top;
    if(top == NULL){
    printf("Stack empty");
    }
    else{
         temp=top;
         top=top->next;
         temp->next=NULL;
    }
   
    return temp;
}




struct Node *head=NULL;
int middleElement=0;

void insertNode(int _data){
    struct Node *newNode=new Node();
    newNode->data=_data;
    newNode->next=NULL;
    if(head ==NULL){
        newNode->next=head;
        head=newNode;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newNode;
    }
    
}

void Display(){
    struct Node *temp=head;
    while(temp!= NULL){
        printf("%d",temp->data);
        temp=temp->next;

    }
}

bool isPalindron(Node *head)
{
        int isPalindrom=false;
        int isPalin =0;
        struct Node *start=head, *temp=head;
        int counter=0;
        while(start != NULL){
        counter++;
        start=start->next;
        }
        middleElement = counter/2;
        if(counter%2 == 0)
        {
            for(int i=0;i<middleElement;i++){
                push(temp->data);
                temp=temp->next;
            }

            while(temp!=NULL){
                struct StackNode *element=pop();
                if(element->data == temp->data){
                    isPalin=isPalin+1;
                }
                else{
                    isPalin=0;
                }
                temp=temp->next;
            }
        }
        else
        {
            for(int i=0;i<middleElement;i++){
                push(temp->data);
                temp=temp->next;
            }
            temp=temp->next;
            while(temp!=NULL){
                StackNode *element=pop();
                if(element->data == temp->data){
                    isPalin=isPalin+1;
                }
                else{
                    isPalin=0;
                }
                temp=temp->next;
            }
        }
    if(isPalin >0)
    isPalindrom=true;
    else
    isPalindrom=false;
    
    return isPalin;

}

int main(){
    insertNode(1);
    insertNode(2);
    insertNode(4);
    insertNode(3);
    insertNode(1);
    bool a = isPalindron(head);
}


/*----------------------------- Practice Day 20 - Linked List - Doubly Linked List --------------------------------*/


#include<stdio.h>
struct Node {
    public :
        int data;
        Node *next;
        Node *prev;
};

struct Node *head,*last;

void insertNode(int _data){
    struct Node *newNode= new Node();
    newNode->data=_data;
    newNode->next=NULL;
    newNode->prev=NULL;


    if(head==NULL){
        newNode->next=head;
        newNode->prev=NULL;
        head=newNode;
    }

    else
    {
        struct Node *currentNode=head;
        while(currentNode->next !=NULL){
            currentNode=currentNode->next;

        }
        currentNode->next=newNode;
        newNode->prev=currentNode;
        last=newNode;
        
    }
    
}

void printDoubleLinkedList(){
    struct Node *currentNode = head;
    while(currentNode != NULL){
        printf("%d ",currentNode->data);
        currentNode=currentNode->next;

    }
}


void printDoubleLinkedListReverse(){
    struct Node *currentNode = last;
    while(currentNode != NULL){
        printf("%d ",currentNode->data);
        currentNode=currentNode->prev;

    }
}


int main(){
    head=NULL;

    insertNode(8);
    insertNode(19);
    insertNode(32);
    insertNode(54);
    insertNode(78);
    insertNode(99);
    insertNode(38);
    printDoubleLinkedList();
    printf("\n");
    printDoubleLinkedListReverse();
    return 0;
}



/*-------------------------------Practice Day 19 - Linked List - Circular linked List ------------------------------

#include<stdio.h>

struct Node {
  public :  
        int data;
        Node *next;
};


struct Node *head;

void insertCircular(int _data){
    struct Node *currentNode = head;
    struct Node *newNode=new Node();
    newNode->data=_data;
    newNode->next=NULL;

    if(head == NULL){
      head=newNode;
      newNode->next=head;
              
    }
    else
    {
        
        while(currentNode->next !=head){
        currentNode=currentNode->next;
        }
        currentNode->next=newNode;
        newNode->next=head;
    }
    
    
        
}

void printCircularList(){
    struct Node *currentNode=head;

    do
    {
        printf("%d ",currentNode->data);
        currentNode=currentNode->next;
     }
     while(currentNode !=head);
    
}

int main(){

    head=NULL;
    insertCircular(6);
    insertCircular(7);
    insertCircular(10);
    insertCircular(5);
    insertCircular(8);
    insertCircular(17);
    insertCircular(71);
    printCircularList();
    
    return 0;
}

/*------------------------------- Practice Day 17-18 - Linked List,Trees,Double LinkedList,Sorting---------------------*/

/*------------------------------- Sorting - > Selection Sort , Merge Sort , Quick Sort -----------------------------------




#include<iostream>
using namespace std;


void swapItems(int *currentMin,int *newMin){
int temp = *currentMin;
    *currentMin=*newMin;
     *newMin=temp;

}



void selectionSort(int arr[],int size){
int min;
for(int i=0;i<size-1;i++){
    min=i;

    for(int j=i+1;j<size;j++){
        if(arr[min] > arr[j])
        {
            min = j;
        }
    }
    swapItems(&arr[i],&arr[min]);

}

}

void printItems(int arrayItems[],int size)
{
    
    for(int i=0;i<size;i++){
        cout<<arrayItems[i]<<" ";

    }
}


    int sizeN1=m-l+1;
    int sizeN2=r-m;


void merge(int arr[],int start,int m,int end){
    int sizeN1=m-start+1;
    int sizeN2=end-m;

    int leftArray[sizeN1],rightArray[sizeN2];

    //fill the LeftArray

    for(int i=0;i<sizeN1;i++)
        leftArray[i]=arr[start+i];

    //fill the rightArray

    for(int j=0;j<sizeN2;j++)
        rightArray[j]=arr[m+1+j];    

    
    int i=0,j=0,k=start;

    while(i<sizeN1 && j<sizeN2){
        if(leftArray[i]<=rightArray[j])
        {
            arr[k]=leftArray[i];
            i++;
        }
        else
        {
            arr[k]=rightArray[j];
            j++;

        }
    k++;        
    }

    while(i<sizeN1){
        arr[k]=leftArray[i];
        i++;
        k++;
    }


    while(j<sizeN2){
        arr[k]=rightArray[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int start,int end){
    if(start < end){

        int m=start + (end -start)/2;
    
        mergeSort(arr,start,m);
        mergeSort(arr,m+1,end);   

        merge(arr,start,m,end);

    }
}



int partitionIndex(int arr[],int start,int end){
    int pivot=arr[end];
    int pivotIndex=start-1;

    for(int i=start;i<end;i++){
        if(arr[i]<pivot){
            pivotIndex++;
            swapItems(&arr[pivotIndex],&arr[i]);
        }
    }
    swapItems(&arr[pivotIndex+1],&arr[end]);  

    return pivotIndex+1;
}

void quickSort(int arr[],int start,int end){
    if(start<end){
        int p=partitionIndex(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);

    }
}


int main(){

    cout<<"Selection Sort";
    int arryItems[] ={ 23,54,87,12,38,81,66,44,99};
    int n=sizeof(arryItems)/sizeof(arryItems[0]);
    //selectionSort(arryItems,n);
    //mergeSort(arryItems,0,n-1);
    quickSort(arryItems,0,n-1);
    cout<<"\n";
    printItems(arryItems,n);
    cout<<"\n";
    
    return 0;
}

/*------------------------------- Binary tree -> Insert , Preorder,PostPrder,Inorder ,breadth First Search --------------

#include<stdio.h>
#include<c++/queue>

struct Node {
    public:
        int data;
        Node *right;
        Node *left;
};

struct Node *root;

struct Node* insertNode(struct Node *root,int _data){
    struct Node *myNode = new Node();
    myNode->data=_data;
    myNode->left=NULL;
    myNode->right=NULL;


    if(root == NULL){
        root=myNode;
    
    }

    if(root->data > _data){
        root->left= insertNode(root->left,_data);
    }
    else if(root->data < _data){
        root->right=insertNode(root->right,_data);
    }

    return root;

} 

void preOrderTraversal(struct Node *root)
{
    if(root == NULL) return;
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}



void inOrderTraversal(struct Node *root)
{
    
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root)
{
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}


void levelOrderTraversal(struct Node *root)
{
    if(root == NULL) return;
    std::queue<struct Node*> q;
    q.push(root);
        while(!q.empty())
        {
            struct Node *temp=q.front();
            printf("%d ",temp->data);
            q.pop();
            if(temp->left !=NULL)
            q.push(temp->left);
            if(temp->right !=NULL)
            q.push(temp->right);
        }

}



int main(){
    root=NULL;
    root=insertNode(root,8);
    root=insertNode(root,3);
    root=insertNode(root,10);
    root=insertNode(root,1);
    root=insertNode(root,6);
    root=insertNode(root,14);
    root=insertNode(root,4);
    root=insertNode(root,7);
    root=insertNode(root,13);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}




/*--------------------------------Linked List -> InsertEnd , Insert At head, Insert At Position , Delete , Reverse -----
#include<stdio.h>
#include<malloc.h>

struct Node {
    public :
        int data;
        Node *next;
};

struct Node *head;

void insertNode(int _data){
    struct Node *newNode=new Node();
    newNode->data=_data;
    newNode->next=NULL;


    if(head == NULL){
        newNode->next=head;
        head=newNode;
        return;
    }


    struct Node *currentNode=head;
    while(currentNode->next != NULL){
        currentNode=currentNode->next;
    }

    currentNode->next=newNode;
}

void deleteNode(int pos){
    struct Node *currentNode = head;

    for(int i=0;i<pos-2;i++){
        currentNode=currentNode->next;
    }

    struct Node *temp = currentNode->next;
    currentNode->next=temp->next;
    free(temp);


}


void printNode(){
    struct Node *temp=head;
    while(temp !=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct Node* reverseLinkedList(){
    struct Node *currentNode,*nextNode,*prev;
    currentNode=head;
    prev=NULL;
    nextNode=NULL;
    
    while(currentNode !=NULL){
    nextNode=currentNode->next;
    currentNode->next=prev;
    prev=currentNode;
    currentNode=nextNode;
    }

    head=prev;

    return head;
}


void insertAtHead(int _data){
    
    struct Node *newNode = new Node();
    newNode->data=_data;
    newNode->next=NULL;

    newNode->next=head;
    head=newNode;
    
}

void insertAtPos(int _data,int pos){
    struct Node *newNode = new Node();
    newNode->data=_data;
    newNode->next=NULL;

    if(head == NULL)
    {
        newNode->next=head;
        newNode=head;
        return;
    }

    struct Node *currentNode=head;
    for(int i=0;i<pos-2;i++)
    {
        currentNode=currentNode->next;
    }
    newNode->next=currentNode->next;
    currentNode->next=newNode;

}



int main(){
    head=NULL;
    insertNode(7);
    insertNode(5);
    insertNode(9);    
    insertNode(8);
    insertNode(10);
    insertNode(6);
    printNode();
    printf("\n");
    insertAtHead(3);
    insertAtHead(5);
    insertAtHead(7);
    insertAtHead(9);
    insertAtHead(2);
    insertAtPos(100,4);
    insertAtPos(101,7);
    printNode();
    printf("\n");
    deleteNode(3);
    printNode();
    printf("\n");
    head=reverseLinkedList();
    printNode();
    printf("\n");
    

    return 0;
}


/*------------------------------- Practice Day 16 - Quick Sorting -----------------
#include<bits/stdc++.h>
using namespace std;

void swap(int* i,int* j){
    int temp=*i;
    *i=*j;
    *j=temp;

}

int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int partitionIndex=start -1;

    for(int i=start;i<end;i++){
        if(arr[i]<pivot){
           
            partitionIndex++;
            swap(&arr[partitionIndex],&arr[i]);
            
        }
    }

    swap(&arr[partitionIndex + 1],&arr[end]);
    return partitionIndex +1;
}


void quickSort(int a[],int start,int end){
    if(start < end){
        int p=partition(a,start,end);
        quickSort(a,start,p-1);
        quickSort(a,p+1,end);
    }
}

void printSortedArray(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout << arr[i]<<",";
    }

}


int main(){
    cout<<"Quick Sort Algorithm";
    int arr[]={23,12,54,65,22,89};
    int size=sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,size-1);
    printSortedArray(arr,size);
    return 0;
}




/*------------------------------- Practice Day 15 - Merge Sorting ----------------

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){

    int sizeN1=m-l+1;
    int sizeN2=r-m;

    int leftArray[sizeN1],rightArray[sizeN2];

    for(int i=0;i<sizeN1;i++){
        leftArray[i]=arr[l+i];
    }
    for(int j=0;j<sizeN2;j++){
        rightArray[j]=arr[m+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i< sizeN1 && j<sizeN2){
        if(leftArray[i]<= rightArray[j])
        {    arr[k]=leftArray[i];
            i++;
        }
        else
        {
            arr[k]=rightArray[j];
            j++;
            
        }
        k++;   

    }

    // upload the remaining items in Mergesort the subarray

    while( i<sizeN1){
        arr[k]=leftArray[i];
        i++;
        k++;
    }

    
    while( j<sizeN2){
        arr[k]=rightArray[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[],int l,int r){
    
    if(l<r){
    
        int m=l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}


void printMergeSortArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i]<<",";
    }

}


int main(){
    int arr[]={75,26,45,18,56,34};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << "Merge Sorted Array";

    mergeSort(arr,0,n-1);
    printMergeSortArray(arr,n);
    return 0;
}


/*------------------------------- Practice Day 14 - Selection Sorting ------------


#include<bits/stdc++.h>
using namespace std;

void swapItems(int *i,int *j){
    int temp = *i ;
    *i=*j;
    *j = temp;
}

void selectionSort(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swapItems(&arr[min],&arr[i]);
    }
}

void printSortedArray(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout << arr[i]<<",";
    }

}

int main(){
    cout<<"Selection sorting";
    int arrItems[]={78,89,56,45,12,23};
    int n= sizeof(arrItems)/sizeof(arrItems[0]);
    selectionSort(arrItems,n);
    cout<< "\n Sorted Array \n";
    printSortedArray(arrItems,n);
    return 0;
}

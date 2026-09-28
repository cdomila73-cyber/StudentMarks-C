#include <stdio.h>
int search(int mark[],int size,int in, int *Nindex);
int show (int mark[],int size,int *Nindex);
int searchi(int mark[],int size,int *Nindex, int Sin, int mk);
int delet(int mark[],int size,int *Nindex,int Sin);
int mtopos(int mark[],int size,int *Nindex, int Sin, int mk);
int main(){
int index;
int option;
int size=10;
int mark[10];
int newMark;
int Nindex;
int in;
int Sin;
int mk;
printf("****Welcome to Marks Manger****\n");
printf("How many indexes are there: \n");
scanf("%d",&Nindex);
printf("Enter the marks of every students before continue;\n");
for(index=0;index<Nindex;index++){
    printf("The marks for index %d :",index+1);
    scanf("%d",&mark[index]);
}
do{
printf("Select the function that you need to do:\n  1.Display all marks\n  2.Search for a mark\n  3.Update the marks by index\n  4.Delete a mark\n  5.Add a marks to a position\n  6.Exit\n");
scanf("%d",&option);
switch (option){
 case 1:
    printf("Marks are loading...\n");
    show(mark,size,&Nindex);
    break;
 case 2:
    printf("Enter the Marks: \n");
    scanf("%d",&in);
    search(mark,size,in,&Nindex);
    break;
 case 3:
    printf("Enter the index number: \n");
    scanf("%d",&Sin);
    printf("Enter the new marks: \n");
    scanf("%d",&mk);
    searchi(mark,size,&Nindex,Sin,mk);
    break;
 case 4:
    printf("Enter the index that you need to delete: \n");
    scanf("%d",&Sin);
    delet(mark,size,&Nindex,Sin);
    break;
 case 5:
    printf("Enter the index position: \n");
    scanf("%d",&Sin);
    printf("Enter the marks: \n");
    scanf("%d",&mk);
    mtopos(mark,size,&Nindex,Sin,mk);


}
}while(option!=6);
return 0;


}


int show (int mark[],int size,int *Nindex){
int i;
for(i=0;i<*Nindex;i++){
    printf("The marks of student %d index is: %d\n",i+1,mark[i]);
}
return 0;
}

int search(int mark[],int size,int in, int *Nindex){
int i;
int found=0;
for (i=0;i<*Nindex;i++){
    if(mark[i]==in){
        printf("Marks found at index %d.\n",i+1);
        found=1;
    }
}
if(!found){
printf("The Mark is not availabele.");
}
return 0;
}

int searchi(int mark[],int size,int *Nindex, int Sin,int mk){

mark[(Sin-1)]=mk;
show(mark,size,Nindex);
return 0;
}

int delet(int mark[],int size,int *Nindex,int Sin){
int i;
if(Sin==0||Sin>*Nindex||Sin<0){
    printf("The action canot be done.\n");
    show(mark,size,Nindex);
    return 0;
}
else if(Sin==*Nindex){
    printf("The operation is done in position %d\n.",Sin);
    (*Nindex)--;
    return 0;
}
else{
    for(i=Sin-1;i<*Nindex;i++){
        mark[i]=mark[i+1];
    }
    (*Nindex)--;
    printf("The operation is done in position %d\n.",Sin);
   return 0;
}
}

int mtopos(int mark[],int size,int *Nindex, int Sin, int mk){
int i;
if(size==*Nindex){
    printf("This action cannot be done.The array is full.");
    return 0;
}
else if(Sin==*Nindex){
    mark[*Nindex]=mk;
    printf("The operation is done in position %d\n.",Sin);
    return 0;
}
else {
    for(i=*Nindex;i>=Sin;i--){
        mark[i+1]=mark[i];
    }
    mark[Sin]=mk;
    printf("The operation is done in position %d\n.",Sin);
    (*Nindex)++;
     return 0;
}
}

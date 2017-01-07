#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct employee{
	char emp_id[5];
	char name[10];
	char surname[20];
	char position[20];
	float salary;
}emp;

void insert_data();
void delete_data();
void search_data();

main(){
	int choice;
	char tmp[]={0};
	do{
		system("cls");
		printf("#################################\n");
		printf("# Welcome to employee system    #\n");
		printf("#################################\n");
		printf("#Please select choice           #\n");
		printf("#1. Insert Data                 #\n");
		printf("#2. Delete Data                 #\n");
		printf("#3. Search Employee Data        #\n");
		printf("#4. Exit                        #\n");
		printf("#################################\n");
		printf("Please select choice(1-4 only) :");
		gets(tmp);
		choice = atoi(tmp);
		if(choice==1) insert_data();
		else if(choice==2) delete_data();
		else if(choice==3) search_data();
	}while(choice!=4);
}
void insert_data(){
	FILE *fp;
	char ans;
	char tmp[]={0};

	if((fp=fopen("employee.txt","ab"))==NULL){
		printf("Cannot open file for insert data\n");
		getch();
		exit(1);
	}
	do{
		printf("\n\nPlease insert employee data\n");
		printf("Employee Id :"); gets(emp.emp_id);
		printf("Name        :"); gets(emp.name);
		printf("Surname     :"); gets(emp.surname);
		printf("Position    :"); gets(emp.position);
		printf("Salary      :"); gets(tmp);
		emp.salary = atof(tmp);
		fwrite(&emp,sizeof(emp),1,fp);
		if(ferror(fp)){
			printf("Error For insert data\n");
			getch();
			exit(1);
		}
		printf("Continue(press C) Or Exit(press E) :");
		ans = getche();
	}while(ans != 'E');
	fclose(fp);
}
void delete_data(){
	FILE *fp;
	int i=0;
	char ans;
	char rec[5];
	if((fp=fopen("employee.txt","rb+"))==NULL){
		printf("Cannot open file for delete data\n");
		getch();
		exit(1);
	}
	printf("\n\nThis is employee for delete\n");
	do{
		while(1){
			fread(&emp,sizeof(emp),1,fp);
			if(ferror(fp)){
				printf("Error to read data for delete\n");
				getch();
				exit(1);
			}
			if(feof(fp))
			break;
			++i;
			printf("%d.%s\t\t",i,emp.emp_id);
		}
		printf("\nDo you want to delete data(Y or N) :");
		ans = getche();
		if(ans=='Y'){
			printf("\nEnter record number :");
			gets(rec);
			fseek(fp,((atoi(rec)-1)*sizeof(emp)),SEEK_SET);
			strcpy(emp.emp_id,"\0");
			fwrite(&emp,sizeof(emp),1,fp);
			if(ferror(fp)){
				printf("Error For delete data\n");
				getch();
				exit(1);
			}
			printf("Delete data complete\n");
		}
		printf("\nContinue(press C) Or Exit(press E) :");
		ans = getche();
		printf("\n");
	}while(ans!='E');
	fclose(fp);
}
void search_data(){
	FILE *fp;
	char ans;
	char id[5];
	if((fp=fopen("employee.txt","rb"))==NULL){
		printf("Cannot open file for search data\n");
		getch();
		exit(1);
	}

	do{
		printf("\n\nPlease enter employee id for search : ");
		scanf("%s",id);

		while(1){
			fread(&emp,sizeof(emp),1,fp);
			if(ferror(fp)){
				printf("Error for search data\n");
				getch();
				exit(1);
			}
			if(feof(fp)) break;
			if(strcmp(id,emp.emp_id)==0){
				printf("Data Found!!!\n");
				printf("Employee Id :%s\n",emp.emp_id);
				printf("Name        :%s\n",emp.name);
				printf("Surname     :%s\n",emp.surname);
				printf("Position    :%s\n",emp.position);
				printf("Salary      :%.2f\n\n",emp.salary);
				break;
			}
		}
		if(strcmp(id,emp.emp_id)!=0)
			printf("No employee in employee id %s\n\n",id);
		printf("Continue(press C) Or Exit(press E) :");
		rewind(fp);
		ans = getche();
		printf("\n");
	}while(ans!='E');
	fclose(fp);
}


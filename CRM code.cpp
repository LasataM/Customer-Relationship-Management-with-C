#include <stdio.h>
#include <string.h>

struct customer
{
    char n[35];
    int a;
    char pn[50][50];
    float p[50];
    char fb[150];
    float total_purchase;
};

void sort_customers(struct customer c[], int n)
{
    int i, j;
    struct customer temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (c[i].total_purchase < c[j].total_purchase)
	{
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

void add()
{
    FILE *fp;
    fp = fopen("customer.txt", "a");
    if (fp == NULL)
    {
        	printf("File cannot be created.\n");
    } 
else
{
        printf("File has been created.\n");
}
int n, i, j, choice;
    do {
        printf("======ADD CUSTOMER RECORDS======\n");
        printf("Enter no. of customers you want to add:");
        scanf("%d", &n);
        struct customer c[n];
        getchar();
        for (i = 0; i < n; i++)
        {
            c[i].total_purchase = 0;
            printf("\nEnter details of customer %d:\n", i + 1);
            printf("Enter name of customer %d:", i + 1);
            scanf("%s", c[i].n);
            getchar();
            printf("Enter no. of products purchased by customer %d:", i + 1);
            scanf("%d", &c[i].a);
            printf("Enter products purchased by customer %d and their price:\n", i + 1);
            for (j = 0; j < c[i].a; j++)
			{
                printf("Product %d:", j + 1);
                scanf("%s", c[i].pn[j]);
                printf("Price of Product %d:", j + 1);
                scanf("%f", &c[i].p[j]);
                c[i].total_purchase = c[i].total_purchase + c[i].p[j];
            }
            getchar();
            printf("Enter feedback:");
            fgets(c[i].fb, 150, stdin);
            getchar();
        }
        sort_customers(c, n);
        for (i = 0; i < n; i++)
       {
            fprintf(fp, "Customer Name: %s\n", c[i].n);
            fprintf(fp, "-------------------------------------------\n");
            fprintf(fp, "S.N.\t\tProduct\t\tPrice\n");
            fprintf(fp, "-------------------------------------------\n");
            for (j = 0; j < c[i].a; j++)
			{
                fprintf(fp, "%d.\t\t%s\t\t%.2f\n", j + 1, c[i].pn[j], c[i].p[j]);
            }
            fprintf(fp, "Total Purchase: %.2f\n", c[i].total_purchase);
            fprintf(fp, "Feedback: %s\n", c[i].fb);
            fprintf(fp, "---------------------------------------------------\n");
        }
        printf("\nRecords stored successfully.");
        printf("\nDo you want to store more records? (1 for yes, 0 for no):");
        scanf("%d", &choice);
    } while (choice == 1);
    fclose(fp);
}

void display()
{
    FILE *fp;
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
    }
    printf("======CUSTOMER RECORDS======\n");
    char line[200];
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }
    fclose(fp);
}

void search()
{
    char sn[35];
    int found = 0;
    FILE *fp;
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
   {
        printf("File cannot be opened.\n");
    }
    printf("======SEARCH RECORDS OF A CUSTOMER======\n");
    printf("Enter the name of the customer you want to search:");
    scanf("%s", sn);
    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, "Customer Name:") != NULL && strstr(line, sn) != NULL)
       {
            found = 1;
            printf("%s", line);
            while (fgets(line, sizeof(line), fp) && !strstr(line, "Customer Name:"))
			{
                printf("%s", line);
            }
            break;
        }
    }
    if (found == 0)
    {
        printf("Record is not present.\n");
    }
    fclose(fp);
}

void totalprice()
{
    char cn[35];
    int found = 0;
    FILE *fp;
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
   {
        printf("File cannot be opened.\n");
    }
    printf("======TOTAL PURCHASE AMOUNT AND AVERAGE AMOUNT OF A CUSTOMER======\n");
    printf("Enter name of the customer:");
    scanf("%s", cn);

    char line[100];
    float tp = 0, c = 0, avg;

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "Customer Name:") != NULL && strstr(line, cn) != NULL)
        {
            found = 1;
            while (fgets(line, sizeof(line), fp) && !strstr(line, "Customer Name:"))
			{
                int sn;
                char product[50];
                float price;
                if (sscanf(line, "%d.\t\t%s\t\t%f", &sn, &product, &price) == 3)
	  			 {
                    tp = tp + price;
                    c = c + 1;
                }
            }
            avg = tp / c;
            printf("Total purchase amount: %.2f\n", tp);
            printf("Average amount: %.2f\n", avg);
            break;
        }
    }
    if (found == 0)
   {
        printf("Record is not present.\n");
    }
    fclose(fp);
}

int main()
{
    start:
    int ch;
    do {
        printf("======CRM SYSTEM MENU======\n");
        printf("1. Add customer records\n");
        printf("2. Display customer records\n");
        printf("3. Search records of a customer\n");
        printf("4. Total purchase amount and average amount of a customer\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
       {
	case 1:
		add();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
	case 4:
		totalprice();
		break;
	case 5:
		break;
	default:
		printf ("Invalid Entry.");
		break;
        }
        }while(ch!=5);
	return 0;
}

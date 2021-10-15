void transact(void)
{ int options,tst=0;
FILE <em>oldrecord,</em>newrecord;
oldrecord=fopen("record.dat","r");
newrecord=fopen("new.dat","w");
printf("Enter the account no. of the Client:"); scanf("%d",&amp;trans.account_number); while (fscanf(oldrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&amp;adding.account_number,adding.client_name,&amp;adding.client_dob.mm,&amp;adding.client_dob.dd,&amp;adding.client_dob.yy,&amp;adding.client_age,adding.client_address,adding.client_citizenship,&amp;adding.client_phone,adding.client_account_type,&amp;adding.client_amount,&amp;adding.client_deposit.mm,&amp;adding.client_deposit.dd,&amp;adding.client_deposit.yy)!=EOF)
{
if(adding.account_number==trans.account_number) { tst=1; if(strcmpi(adding.client_account_type,"fixed1")==0||strcmpi(adding.client_account_type,"fixed2")==0||strcmpi(adding.client_account_type,"fixed3")==0) { printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!"); fordelay(1000000000); system("cls"); menu(); } printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):"); scanf("%d",&amp;options); if (options==1) { printf("Enter the amount you want to deposit:P "); scanf("%f",&amp;trans.client_amount); adding.client_amount+=trans.client_amount; fprintf(newrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",adding.account_number,adding.client_name,adding.client_dob.mm,adding.client_dob.dd,adding.client_dob.yy,adding.client_age,adding.client_address,adding.client_citizenship,adding.client_phone,adding.client_account_type,adding.client_amount,adding.client_deposit.mm,adding.client_deposit.dd,adding.client_deposit.yy); printf("\n\nDeposited successfully!"); } else { printf("Enter the amount you want to withdraw:P "); scanf("%f",&amp;trans.client_amount); adding.client_amount-=trans.client_amount; fprintf(newrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",adding.account_number,adding.client_name,adding.client_dob.mm,adding.client_dob.dd,adding.client_dob.yy,adding.client_age,adding.client_address,adding.client_citizenship,adding.client_phone,adding.client_account_type,adding.client_amount,adding.client_deposit.mm,adding.client_deposit.dd,adding.client_deposit.yy); printf("\n\nWithdrawn successfully!"); } } else { fprintf(newrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",adding.account_number,adding.client_name,adding.client_dob.mm,adding.client_dob.dd,adding.client_dob.yy,adding.client_age,adding.client_address,adding.client_citizenship,adding.client_phone,adding.client_account_type,adding.client_amount,adding.client_deposit.mm,adding.client_deposit.dd,adding.client_deposit.yy); }
}
fclose(oldrecord);
fclose(newrecord);
remove("record.dat");
rename("new.dat","record.dat");
if(tst!=1)
{
printf("\n\nRecord not found!!");
transact_invalid:
printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&amp;exits);
system("cls");
if (exits==0)
transact();
else if (exits==1)
menu();
else if (exits==2)
close();
else
{
printf("\nInvalid!");
goto transact_invalid;
}
}
else
{
printf("\nEnter 1 to go to the main menu and 0 to exit:");
scanf("%d",&amp;exits);
system("cls");
if (exits==1)
menu();
else
close();
}
}

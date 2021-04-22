#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

int first,last,check,count=0;
void main()
{

	char a[100],fn[10],ln[10],pwd[10],uid[10],c,c1[50],c2[50],bu,g1,g2,g3,g4,g5,d,h,h1;
	int queue[5],element,y,r,r1=0,f,b,b1,p1,pr1,gup,p2,pr2,p3,pr3,p4,pr4,p5,pr5,lc,lc1=0,lc2,lc3,lc4,lc5,l1,li1,l2,li2,l3,li3,l4,li4,l5,li5,o;

	void addfollower();
	void removefollower();
	void displayfollower();
	last=first=0;
	clrscr();
	//registeruser();
	printf("\n\n\n\n\n-----------------------------------------------------------------------------");
	printf("\n\t\t\t\tWelcome to ZOHO POINT");
	printf("\n-----------------------------------------------------------------------------");
	printf("\n Register the user to social media platform");
	printf("\n\n\t\t    First Name: ");
	scanf("%s",&fn);
	printf("\n\t\t    Last Name : ");
	scanf("%s",&ln);
	printf("\n\t\t    Password  : ");
	scanf("%s",&pwd);
	printf("\n\t\t    Create your UserScreenId: ");
	scanf("%s",&uid);
	printf("\n\n-------------------------------------------------------------------------------------\n");

	clrscr();
	printf("\n\n\t\tYour Account was Successfully Created!");

	do
	{

		printf("\n\nSelect Option which you want to see now....");


		printf("\n\n\t   1. To Post your feed");
		printf("\n\t   2. Follow Users");
		printf("\n\t   3. Unfollow Users");
		printf("\n\t   4. block User");
		printf("\n\t   5. to get post feed of particular user");
		printf("\n\t   6. user feed likes count");
		printf("\n\t   7. Delete your user account");
		printf("\n\t   0. Exit");

		printf("\n\n\tEnter your choice: ");
		scanf("%d",&o);

		if(o==1)
		{
		clrscr();
		printf("------------------------------------------------------------------------------");
		printf("\n\t\tZoho Point | POST FEED @myaccount|");
		printf("\n------------------------------------------------------------------------------");
		printf("\nIf you want to post in your page(Y/N): ");
		scanf("%s",&c);
		if(c=='y' || c=='Y')
			printf("\nIf yes create your post(text format only): ");
		if(c=='y' || c=='Y')
		{
			fflush(stdin);
			scanf("%[^\n]s",c1);
			printf("Your post is successfully posted!");
		}


		printf("\nGive the reactions for the post feed");
		printf("\n\t1. Like");
		printf("\n\t2. Unlike");
		printf("\n\t3. Hide");
		printf("\nChoose Reaction: ");
		scanf("%d",&r);
		if(r==1)
		{
			r1++;
			printf("Your like added in this post!\n");
		}
		if(r==2)
		{
			r1++;
			printf("This Post has Unlike :(\n");
		}
		if(r==3)
		{
			printf("Post was Hided\n");
		}
		getch();
	}
		clrscr();

		if(o==2)
		{
		printf("\n------------------------------------------------------------------------------");
		printf("\n\t\t Zoho Point | FOLLOW USER");
		printf("\n------------------------------------------------------------------------------");
		printf("\n Choose your Followers below the Userlist");

		printf("\n\t1. User_1@ZoHo");
		printf(	"\n\t2. User_2@ZoHo");
		printf("\n\t3. User_3@ZoHo");
		printf("\n\t4. User_4@ZoHo");
		printf("\n\t5. User_5@ZoHo");

		for(r=0;r<=4;r++)
		{
			printf("\nChoose your Followers:(note press 0 to next page):  ");
			scanf("%d",&f);
			if(f!=0)
			{
				if(f==1)
				{
					printf("Now you are started following User_1@ZoHo\n");
					addfollower(queue,f);
				}
				if(f==2)
				{
					printf("Now you are started following User_2@ZoHo\n");
					addfollower(queue,f);
				}
				if(f==3)
				{
					printf("Now you are started follwing User_3@ZoHo\n");
					addfollower(queue,f);
				}
				if(f==4)
				{
					printf("Now you are started follwing User_4@ZoHo\n");
					addfollower(queue,f);
				}
				if(f==5)
				{
					printf("Now you are started following User_5@ZoHo\n");
					addfollower(queue,f);
				}
			}
			else
			{
				r=8;
			}
		}
		clrscr();

		printf("\tYour Follower List");
		displayfollower(queue);
		getch()	;
	}
		clrscr();

	 if(o==3)
	{
		printf("-------------------------------------------------------------------------------");
		printf("\n\t\t Zoho Point | UNFOLLOW USER");
		printf("\n------------------------------------------------------------------------------");

		printf("\nYour follower list \n");

		displayfollower(queue);


		printf("\nDo you want to unfollow the first user \n/*where we are using queue concept so we can able to remove the first queue*/\n\nif yes press the user number otherwise zero....other numbers are not eligible: ");
		for(r=0;r<=4;r++)
		{
			if(r>0)
				printf("\nEnter the user to be unfollowed: ");
			scanf("%d",&h1);
			if(h1!=0 && h1<=5)
			{
				removefollower(queue);
				printf("The user %d was unfollowed",h1);
				printf("\nif you want to unfollow user again then press any key or to exit press 0:");
				scanf("%d",&h1);
				if(h1==0)
					break;
			}
		}
		getch();
	}
	clrscr();

	if(o==4)
	{
		printf("-----------------------------------------------------------------------------");
		printf("\n\t\t Zoho Point | BLOCK USER");
		printf("\n------------------------------------------------------------------------------");
		displayfollower(queue);
		printf("\n\nIf you want to Block any user from this list? (Y/N): ");
		scanf("%s",&bu);


			if(bu=='Y' || bu=='y')
			displayfollower(queue);
			printf("\n\tChoose your BLOCK id from your follower list: ");
			printf("\n(Note only the users numbers other values are not permitted)\n");
			scanf("%d",&b);
			if(b==1)
			{
				printf("The USer_1@ZoHo id is BLOCKED !!\n");
				b1=1;
			}
			if(b==2)
			{
				printf("The User_2@ZoHo id is BLOCKED !!\n");
				b1=2;
			}
			if(b==3)
			{
				printf("The User_3@ZoHo id is BLOCKED !!\n");
				b1=3;
			}
			if(b==4)
			{
				printf("The User_4@ZoHo id is BLOCKED !!\n");
				b1=4;
				}
			if(b==5)
			{
				printf("The USer_5@ZoHo id is BLOCKED !!");
				b1=5;
			}
			//getuserfeed()
			getch();
		}
		clrscr();
		if(o==5)
		{
			printf("\n----------------------------------------------------------------------------");
			printf("\n\t\t Zoho Point | GET THE USER FEED");
			printf("\n----------------------------------------------------------------------------");
			printf("\n\nChoose the Particular user postfeed");
			printf("\n\t1. User_1@ZoHo");
			printf("\n\t2. User_2@ZoHo");
			printf("\n\t3. User_3@ZoHo");
			printf("\n\t4. User_4@ZoHo");
			printf("\n\t5. User_5@ZoHo");
			printf("\n\tChoose the USer: ");
			scanf("%d",&gup);

			if(gup==1 && b1!=1)
			{
				int l1=20,u1=5, li1=30,ui1=8;
				lc1=l1+li1;
				printf("\nUser_1@ZoHo");
				printf("\n   POST 1: Dedication! Hardwork! Success!");
				printf("\n   Likes: %d\t Unlike: %d",l1,u1);  //hide
				printf("\n   POST 2: Start you Brightful career with ZOHO corp:) ");
				printf("\n   Likes: %d\t Unlike: %d",li1,ui1);  //balance hide

				printf("\nIf you want to give any reactions to this User's Post? (Y/N): ");
				fflush(stdin);
				scanf("%c",&g1);

				if(g1=='Y' || g1==y)
				{
					printf("\n\t1. POST 1");
					printf("\n\t2. POST 2");
					printf("\n\tChoose your post: ");
					scanf("%d",&p1);
					printf("\n\t(Give the reactions: 1. Likes  2. Dislike  3, Hide): ");
					scanf("%d",&pr1);

					if(pr1==1)
					{
						printf("Cheers :) Your like is added in POST %d !\n",p1);
					}
					if(pr1==2)
					{
						printf("You give a dislike for this post %d\n",p1);
					}
					if(pr1==3)
					{
						printf("This post was Hided");
					}
				}
			}
			else if(b1==1 && gup==1)
			{
				printf("Sorry this account is blocked by you");
			}

			if(gup==2 && b1!=2)
			{
				int l2=36,u2=9, li2=10,ui2=0;
				lc2=l2+li2;
				printf("\nUser_2@ZoHo");
				printf("\n   POST 1: Buil your future with us:)");
				printf("\n   Likes: %d\t Unlike: %d",l2,u2);
				printf("\n   POST 2: Failure is the steping stone for success!! ");
				printf("\n   Likes: %d\t Unlike: %d",li2,ui2);

				printf("\nIf you want to give any reactions to this User's Post? (Y/N)");
				fflush(stdin);
				scanf("%c",&g2);

				if(g2=='Y' || g2==y)
				{
					printf("\n\t1. POST 1");
					printf("\n\t2. POST 2");
					printf("\n\tChoose your post: ");
					scanf("%d",&p2);
					printf("\n\t(Give the reactions) 1. Likes  2. Dislike  3, Hide): ");
					scanf("%d",&pr2);

					if(pr2==1)
					{
						printf("Cheers :) Your like is added in POST %d !\n",p2);
					}
					if(pr2==2)
					{
						printf("You give a dislike for this post %d\n",p2);
					}
					if(pr2==3)
					{
						printf("This post was Hided");
					}
				}
			}
			else if(b1==2 && gup==2)
			{
				printf("Sorry this account is blocked by you");
			}
			if(gup==3 && b1!=3)
			{
				int l3=18,u3=3, li3=19,ui3=9;
				lc3=l3+li3;
				printf("\nUser_3@ZoHo");
				printf("\n   POST 1: Let's Shine in your own way!!!");
				printf("\n   Likes: %d\t Unlike: %d",l3,u3);  //hide
				printf("\n   POST 2: Experience is the Better Teacher!");
				printf("\n   Likes: %d\t Unlike: %d",li3,ui3);  //balance hide

				printf("\nIf you want to give any reactions to this User's Post? (Y/N): ");
				fflush(stdin);
				scanf("%c",&g3);

				if(g3=='Y' || g3=='y')
				{
					printf("\n\t1. POST 1");
					printf("\n\t2. POST 2");
					printf("\n\tChoose your post: ");
					scanf("%d",&p3);
					printf("\n\t(Give the reactions) 1. Likes  2. Dislike  3, Hide): ");
					scanf("%d",&pr3);

					if(pr3==1)
					{
						printf("Cheers :) Your like is added in POST %d!\n",p3);
					}
					if(pr3==2)
					{
						printf("You give a dislike for this post %d\n",p3);
					}
					if(pr3==3)
					{
						printf("This post was Hided");
					}
				}
			}
			else if(b1==3 && gup==3)
			{
				printf("Sorry this account is blocked by you");
			}
			if(gup==4 && b1!=4)
			{
				int l4=50,u4=10, li4=100,ui4=0;
				lc4=l4+li4;
				printf("\nUser_4@ZoHo");
				printf("\n   POST 1: Do Your Best!!!");
				printf("\n   Likes: %d\t Unlike: %d",l4,u4);  //hide
				printf("\n   POST 2: If You can Dream it! You can do it-Dr.APJ Abdul Kalam!!! ");
				printf("\n   Likes: %d\t Unlike: %d",li4,ui4);  //balance hide

				printf("\nIf you want to give any reactions to this User's Post? (Y/N): ");
				fflush(stdin);
				scanf("%c",&g4);

				if(g4=='Y' || g4=='y')
				{
					printf("\n\t1. POST 1");
					printf("\n\t2. POST 2");
					printf("\n\tChoose your post: ");
					scanf("%d",&p4);
					printf("\n\t(Give the reactions) 1. Likes  2. Dislike  3, Hide): ");
					scanf("%d",&pr4);

					if(pr4==1)
					{
						printf("Cheers :) Your like is added in POST %d !\n",p4);
					}
					if(pr4==2)
					{
						printf("You give a dislike for this post %d\n",p4);
					}
					if(pr4==3)
					{
						printf("This post was Hided");
					}
				}
			}
			else if(b1==4 && gup==4)
			{
				printf("Sorry this account is blocked by you");
			}
			if(gup==5 && b1!=5)
			{
				int l5=20,u5=5, li5=30,ui5=8;
				lc5=l5+li5;
				printf("\nUser_5@ZoHo");
				printf("\n   POST 1: S(z)mall Office! Home Office! ");
				printf("\n   Likes: %d\t Unlike: %d",l5,u5);  //hide
				printf("\n   POST 2: Made in India, Made for the World ");
				printf("\n   Likes: %d\t Unlike: %d",li5,ui5);  //balance hide

				printf("\nIf you want to give any reactions to this User's Post? (Y/N): ");
				fflush(stdin);
				scanf("%c",&g5);

				if(g5=='Y' || g5=='y')
				{
					printf("\n\t1. POST 1");
					printf("\n\t2. POST 2");
					printf("\n\tChoose your post: ");
					scanf("%d",&p5);
					printf("\n\t(Give the reactions) 1. Likes  2. Dislike  3, Hide");
					scanf("%d",&pr5);

					if(pr5==1)
					{
						printf("Cheers :) Your like is added in POST %d !\n",p5);
					}
					if(pr5==2)
					{
						printf("You give a dislike for this post %d\n",p5);
					}
					if(pr5==3)
					{
						printf("This post was Hided");
					}
				}
			}
			else if(b1==5 && gup==5)
			{
				printf("Sorry this account is blocked by you");
			}
			getch();

			clrscr();
		}



		if(o==6)
		{
			printf("\n-----------------------------------------------------------------------------");
			printf("\n\t\t Zoho Point | GET FEED LIKE COUNT");
			printf("\n------------------------------------------------------------------------------");
			printf("\n\n Get the Likes Count of particular User");
			printf("\n\t1. User_1@ZoHo");
			printf("\n\t2. User_2@ZoHo");
			printf("\n\t3. User_3@ZoHo");
			printf("\n\t4. User_4@ZoHo");
			printf("\n\t5. User_5@ZoHo");
			printf("\n\tChoose Your UserFeed: ");
			scanf("%d",&lc);

			if(lc==1)
			{
				printf("\nThe User_1@Zoho has a %d Likes!",lc1);
			}
			if(lc==2)
			{
				printf("\nThe User_2@ZoHO has a %d Likes!",lc2);
			}
			if(lc==3)
			{
				printf("\nThe User_3@ZoHo has a %d Likes!",lc3);
			}
			if(lc==4)
			{
			printf("\nThe User_4@ZoHo has a %d Likes!",lc4);
			}
			if(lc==5)
			{
				printf("\nThe User_5@ZoHo has a %d Likes!",lc5);
			}


			getch();
		}

		clrscr();
		if(o==7)
		{
			printf("------------------------------------------------------------------------------");
			printf("\n\t\t Zoho Point | DELETE USER");
			printf("\n------------------------------------------------------------------------------");
			printf("\n\nDo you want to delete the user from this social media platform? (Y/N):");
			scanf("%s",&d);

			if(d=='Y' || d=='y')
			{
				printf("\n\t Your User account %s was deleted!",uid);
			}
			getch();
			clrscr();
		 }
	}while(o!=0);

	printf("\n\tThank You for using Zoho Point!!! ");

	getch();
}

void addfollower(queue, f)
int queue[5], f;
{
	if(last<5)
	{
		last++;
		queue[last]= f;
		if(!first)
			first=1;

		check=0;
		count++;
	}
}
void displayfollower(queue)
int queue[5];
{
	int ls;

	for(ls=first; ls<last+1; ls++)
	{
		printf("\nUser: %d",queue[ls]);
	}
	printf("\n");
}
void removefollower(queue,h1)
int queue[5];
{
	int f;

	if(first)
	{
		if(h1==first)
		{
			f = queue[first];
			check=0;
			count--;
		}
		first++;
	}


}


















//Header files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Functions included.
void mainMenu();
void teamDetails();
void newScorecard();
void scoringProcess();
void defaultScores();
void scoreSheet();
void convertToOver(int balls1);
void switchb();

//Global variables used.
int score=0,overs=0,ball=0,ballrun=0,bm1=0,bm2=0,bowlid=0;

//Batsmen structure(To store batsman details like name, runs, id etc)
struct batsmen
{
    int runs;
    char name[10];
    int balls;
    int id;
    int out;
    int isBatting;
}bat[11];

//Bowler structure(To store bowler details like name, wickets taken, id etc)
struct bowlers
{
    int balls;
    char name[20];
    int wickets ;
    int id;
    int bowling;
}bowl[11];

//Main function
int main()
{
    mainMenu();
}

//Main menu(Where you take choice from the user)
void mainMenu()
{
    system("cls");
    int ch;
    printf("\n\n\n\n\n\n\n\t\t\t\t\tCRICKET SCORECARD MANAGEMENT SYSTEM\n\n");
    printf("\t\t\t\tNOTE: Use this program when you already know \n\t\t\t\twhich team is going to BAT first.\n\n");
    printf("\t\t\t\t1.Create new scoresheet.\n\t\t\t\t2.Exit.\n");
    printf("\t\t\t\tEnter your choice(1 or 2): ");
    scanf("%d",&ch);
    if(ch==1)
    {
        newScorecard();
    }
    else if(ch==2)
    exit(0);
    else
    {
        mainMenu();
    }
}

//If the choice is 1 then this function is executed.
void newScorecard()
{
    defaultScores();
    teamDetails();
    scoringProcess();

}

//Function to get team details(Batting and bowling team)
void teamDetails()
{
    system("cls");
    printf("\n\n\n\tPLAYER DETAILS\n\n");
    printf("\tEnter BATTING team players names(11 players):\n");
    for(int i=1;i<=11;i++)
    {
        printf("\tBatsman %d: ",i);
        bat[i].id=i;
        scanf("%s",&bat[i].name);
    }
    system("cls");
    printf("\n\n\n\tPLAYER DETAILS\n\n");
    printf("\tEnter BOWLING team players names(11 players):\n");
    for(int j=1;j<=11;j++)
    {
        printf("\tPlayer %d: ",j);
        bowl[j].id=j;
        scanf("%s",&bowl[j].name);
    }
    system("cls");
    printf("\n\n\n\n\n\tENTER NUMBER OF OVERS: ");
    scanf("%d",&overs);
}

//This function handles the scoring process.(very important and very difficult to understand)
void scoringProcess()
{
    int b1,b2,nb,bo;
    char b11,b22;
    char brun='1';


    while(ball<=overs*6)
    {

        if(ball==overs*6)
        {
            system("cls");
            printf("\n\n\t\t\t\t\tFINAL SCORESHEET");
            scoreSheet1();
            getch();
        }

        if(ball==0)
        {
            top:
            system("cls");
            printf("\n\n\n\t\t SELECT BATSMAN\n\n");
            printf("\tID  Name        Runs      Balls\n");
            for(int i = 1; i<=11;i++)
            {
                printf("\t%-3d %-10s: %-3dRuns  %-3dBalls\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
            }
            printf("\n\tEnter FIRST Batsman ID (1-11): ");
            scanf("%c",&b11);
            if(isalpha(b11))
            {
                goto top;
            }
            b1=b11-'0';
            if(b1<1 || b1>11)
            {
                printf("\n\tError:Invalid choice.");
                goto top;
            }else
            {
                bm1=b1;
                bat[b1].isBatting=1;
            }
            top1:
            printf("\tEnter SECOND Batsman ID (1-11): ");
            scanf("%d",&b2);
            if(bat[b2].isBatting)
                {
                    printf("\tBatsman %d:%s is already batting.\n\tENTER AGAIN\n",bat[b2].id,bat[b2].name);
                    goto top1;
                }
            if(b2<1 || b2>11)
            {
                printf("\n\tError:Invalid choice.");
                goto top1;
            }else
            {
                bm2=b2;
                bat[b2].isBatting=1;
            }
        }


        if(ball%6==0 && ball<overs*6)
        {
            system("cls");
            printf("\n\n\n\t\t SELECT BOWLER\n\n");
            printf("\tID  Name        Balls      Wickets\n");
            for(int j=1;j<=11;j++)
            {
                printf("\t%-3d %-10s: %-3dBalls  %-3dWickets\n",bowl[j].id,bowl[j].name,bowl[j].balls,bowl[j].wickets);
            }
            printf("\n\n\tEnter BOWLER ID (1-11): ");
            scanf("%d",&bo);
            bowlid=bo;
            if(ball>5)
                switchb();
            bowl[bo].bowling=1;
        }

        int no_of_out=0;

        label:
        if(ball<overs*6)
        {
            system("cls");
            scoreSheet();
            printf("\n\n\tEnter Ball(1-6 runs, 'w' for out): ");
            scanf(" %c",&brun);
            if(brun=='0')
            {
                ballrun='0'-'0';
                bat[bm1].runs+=0;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            } else if(brun=='1')
            {
                ballrun='1'-'0';
                bat[bm1].runs+=1;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
                switchb();
            } else if(brun=='2')
            {
                ballrun='2'-'0';
                bat[bm1].runs+=2;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            } else if(brun=='3')
            {
                ballrun='3'-'0';
                bat[bm1].runs+=3;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
                switchb();
            } else if(brun=='4')
            {
                ballrun='4'-'0';
                bat[bm1].runs+=4;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            } else if(brun=='6')
            {
                ballrun='6'-'0';
                bat[bm1].runs+=6;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            } else if(brun=='w'||brun=='W')
            {
                bat[bm1].out=1;
                bowl[bowlid].wickets++;
                bowl[bowlid].balls++;
                for(int a=1;a<=11;a++)
                {
                    if(bat[a].out==1)
                    no_of_out++;
                }
                if(no_of_out==10)
                {
                    ball++;
                    system("cls");
                    printf("\n\n\t\t\t\t\tFINAL SCORESHEET");
                    scoreSheet1();
                    getch();
                    break;
                }
                bat[bm1].isBatting=0;
                printf("\tBatsman %d: %s is out.",bat[bm1].id,bat[bm1].name);
                first:
                printf("\n\tEnter new batsman(1-11): ");
                scanf("%d",&nb);
                if(bat[nb].isBatting)
                {
                    printf("\tBatsman %d:%s is already batting.\n\tENTER AGAIN",bat[nb].id,bat[nb].name);
                    goto first;
                }
                if(bat[nb].out)
                {
                    printf("\tBatsman %d:%s is already out.\n\tENTER AGAIN",bat[nb].id,bat[nb].name);
                    goto first;
                }
                bat[bm1].balls++;
                bat[nb].isBatting=1;
                bm1=nb;
            }else
            {
                printf("\n\tInvalid possibility.Enter again.");
                goto label;
            }
        }
        ball++;
        score=score+ballrun;
   }
}

//Function to set default values
void defaultScores()
{
    for(int i =0;i<11;i++)
    {
        bat[i].balls=0;
        bat[i].runs=0;
        bat[i].out=0;
        bat[i].isBatting=0;
        bowl[i].balls=0;
        bowl[i].wickets=0;
        bowl[i].bowling = 0;
    }
}

//Function to display the scoresheet.
void scoreSheet1()
{
    //system("cls");
    printf("\n\n\t\t\tBATTING TEAM STATS:\n\n");
    for(int i = 1; i<=11;i++)
    {
        if(bat[i].out)
        printf("\t\t\t%-3d%-10s: %-3dRuns  %-3dBalls  OUT\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
        else
        {
            if(i==bm1)
            printf("\t\t\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Strike\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
            else if(i==bm2)
            printf("\t\t\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Non Strike\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
            else
            printf("\t\t\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);

        }
    }
    printf("\n\t\t\tBOWLING TEAM STATS:\n\n");
    for(int j =1;j<=11;j++)
    {
        if(bowl[j].bowling)
            printf("\t\t\t%-3d%-10s: %-3dBalls  %-3dWickets\n",bowl[j].id,bowl[j].name,bowl[j].balls,bowl[j].wickets);
    }
    printf("\n\t\t\tOVERS: ");convertToOver(ball);
    printf("\t\t\t\tSCORE: %d",score);
}

void scoreSheet()
{
    //system("cls");
    printf("\n\n\t\t\tBATTING TEAM STATS:\n\n");
    for(int i = 1; i<=11;i++)
    {
        if(bat[i].out)
        printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  OUT\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
        else
        {
            if(i==bm1)
            printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Strike\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
            else if(i==bm2)
            printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Non Strike\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);
            else
            printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT\n",bat[i].id,bat[i].name,bat[i].runs,bat[i].balls);

        }
    }
    printf("\n\tBOWLING TEAM STATS:\n\n");
    for(int j =1;j<=11;j++)
    {
        if(bowl[j].bowling)
            printf("\t%-3d%-10s: %-3dBalls  %-3dWickets\n",bowl[j].id,bowl[j].name,bowl[j].balls,bowl[j].wickets);
    }
    printf("\n\tOVERS: ");convertToOver(ball);
    printf("\t\tSCORE: %d",score);
}

//Function to convert balls to overs.(ex: 7 balls to 1.1 overs)
void convertToOver(int balls1)
{
    int o=0,b=0;
    o=balls1/6;
    b=balls1%6;
    printf("%d.%d",o,b);
}

//Function to swtich batsman position(from strike to no strike)
void switchb()
{
    int temp=0;
    temp=bm1;
    bm1=bm2;
    bm2=temp;
}

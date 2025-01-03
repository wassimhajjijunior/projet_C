#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void inputCampaignData(campaign *c) {
    printf("Enter campaign name: ");
    scanf("%ms", &c->name); // Dynamically allocate memory for name
    printf("Enter goal amount: ");
    scanf("%lf", &c->goal);
    printf("Enter current sum: ");
    scanf("%lf", &c->currentSum);

    c->history = malloc(10000 * sizeof(CampaignHistoryEntry)); // Allocate memory for history
    if (!c->history) {
        perror("Failed to allocate memory for campaign history");
        exit(EXIT_FAILURE);
    }
    c->historyCount = 0;
}


void addCampaigns (campaignDB *campaigns)
{
    int t;
    printf("how many campains do you want to add?\n");
    scanf("%d", &t); 
    while (t--)
    {
        if(campaigns->campaignCount<1000)
        {
            campaign c;
            inputCampaignData(&c);
            campaigns->DB[campaigns->campaignCount]=c;
            campaigns->campaignCount++;
        }
        else
        {
            printf("We can't take on any more campaigns\n");
            break;
        }
    }

}
void inputDonorData(donor *d) {
    printf("Enter donor name: ");
    scanf("%ms", &d->name); // Dynamically allocate memory for name
    printf("Enter donor wallet balance: ");
    scanf("%lf", &d->wallet);

    d->history = malloc(10000 * sizeof(DonorHistoryEntry)); // Allocate memory for history
    if (!d->history) {
        perror("Failed to allocate memory for donor history");
        exit(EXIT_FAILURE);
    }
    d->historyCount = 0;
}

void addDonors (donorDB *donors)
{
    int t;
    printf("how many donors do you want to add?\n");
    scanf("%d", &t); 
    while (t--)
    {
        if(donors->donorCount<10000)
        {
            donor d;
            inputDonorData(&d);
            donors->DB[donors->donorCount]=d;
            donors->donorCount++;
        }
        else
        {
            printf("We can't accept more donors\n");
            break;
        }
    }
}


void makedonation(int pos_donor,int pos_campaign,donorDB *donors,campaignDB *campaigns)  //donor's viewpoint
{
    donor *d = &donors->DB[pos_donor];  
    campaign *c = &campaigns->DB[pos_campaign];
    if(d->historyCount>=10000 || c->historyCount>=10000)
    {
        printf("We can't process this donation\n");
        return;
    }

    printf("how much do you want to donate?:\n");
    long double amount;
    scanf("%Lf", &amount); 
    
    
    char * campaign_name=c->name;
    char * donor_name=d->name;

    c->history[c->historyCount].donorName = strdup(d->name);
    c->history[c->historyCount].donationAmount = amount;

    d->history[d->historyCount].campaignName = strdup(c->name);
    d->history[d->historyCount].donationAmount = amount;

    d->wallet -= amount;
    c->currentSum += amount;
    d->historyCount++;
    c->historyCount++;
    if(c->currentSum>=c->goal)
    {
        //deleting the element by swapping it with the last element and resizinng the array accordingly
        campaign aux=campaigns->DB[campaigns->campaignCount];
        campaigns->DB[campaigns->campaignCount] =*c;
        campaigns->DB[pos_campaign]=aux;
        campaigns->campaignCount--;
    }
    if(d->wallet<=0)
    {
        //deleting the element by swapping it with the last element and resizinng the array accordingly
        donor aux=donors->DB[donors->donorCount];
        donors->DB[donors->donorCount]=*d;
        donors->DB[pos_donor]=aux;
        donors->donorCount--;
    }

}
void aquireDonation(donorDB *donors, campaignDB *campaigns) //charity's viewpoint
{
    //bch nlawej 3la akther donor 3andou flous w bch na3tih el campaign that needs it the most; 
    long double min_ratio=1; int pos_campaign=0;
    for (int i = 0; i <campaigns->campaignCount ; i++)
    {
        campaign temp=campaigns->DB[i];
        if((temp.currentSum/temp.goal)<min_ratio)
        {
            min_ratio=temp.currentSum/temp.goal;
            pos_campaign=i;
        }
    }

    long double max=0; int pos_donor =0;
    for (int i = 0; i <donors->donorCount ; i++)
    {
        donor temp=donors->DB[i];
        if(temp.wallet>max)
        {
            max=temp.wallet;
            pos_donor=i;
        }
    }
    makedonation(pos_donor,pos_campaign,donors,campaigns);

}


// print donor history
void printDonorHistory(donor *d) {
    printf("Donor Name: %s\n", d->name);
    printf("Wallet Balance: %.2lf\n", d->wallet);
    printf("Donation History:\n");
    for (int i = 0; i < d->historyCount; i++) {
        printf("  Campaign: %s, Amount: %.2lf\n", d->history[i].campaignName, d->history[i].donationAmount);
    }
    printf("\n");
}


// print campain history
void printCampaignHistory(campaign *c) {
    printf("Campaign Name: %s\n", c->name);
    printf("Goal: %.2lf, Current Sum: %.2lf\n", c->goal, c->currentSum);
    printf("Donation History:\n");
    for (int i = 0; i < c->historyCount; i++) {
        printf("  Donor: %s, Amount: %.2lf\n", c->history[i].donorName, c->history[i].donationAmount);
    }
    printf("\n");
}


// print compaignDB:name,goal and currentSum 
void printCampaignDB(campaignDB *campaigns) {
    printf("Campaign Database:\n");
    for (int i = 0; i < campaigns->campaignCount; i++) {
        campaign *c = &campaigns->DB[i];
        printf("  Campaign Name: %s\n", c->name);
        printf("  Goal: %.2lf\n", c->goal);
        printf("  Current Sum: %.2lf\n", c->currentSum);
        // hedhi bich itkoun wadhha ; separe beha
        printf("-----------------------\n");
    }
}


// print donorDB:name and how much money he have
void printDonorDB(donorDB *donors) {
    printf("Donor Database:\n");
    for (int i = 0; i < donors->donorCount; i++) {
        donor *d = &donors->DB[i];
        printf("  Donor Name: %s\n", d->name);
        printf("  Wallet Balance: %.2lf\n", d->wallet);
        printf("-----------------------\n");
    }
}



int main(void)
{
    donorDB donors;
    donors.donorCount = 0;

    campaignDB campaigns;
    campaigns.campaignCount = 0;

    printf("Adding campaigns:\n");
    addCampaigns(&campaigns);

    printf("Adding donors:\n");
    addDonors(&donors);

    printf("\nPrinting Campaign Database:\n");
    printCampaignDB(&campaigns);

    printf("\nPrinting Donor Database:\n");
    printDonorDB(&donors);

    if (donors.donorCount > 0 && campaigns.campaignCount > 0) {
        printf("\nMaking a donation:\n");
        makedonation(0, 0, &donors, &campaigns); 
    }

    if (donors.donorCount > 0) {
        printf("\nPrinting Donor 0's History:\n");
        printDonorHistory(&donors.DB[0]);
    }

    if (campaigns.campaignCount > 0) {
        printf("\nPrinting Campaign 0's History:\n");
        printCampaignHistory(&campaigns.DB[0]);
    }

    if (donors.donorCount > 0 && campaigns.campaignCount > 0) {
        printf("\nAcquiring donation (charity's perspective):\n");
        aquireDonation(&donors, &campaigns);
    }

    printf("\nUpdated Campaign Database:\n");
    printCampaignDB(&campaigns);

    printf("\nUpdated Donor Database:\n");
    printDonorDB(&donors);

    return 0;
}

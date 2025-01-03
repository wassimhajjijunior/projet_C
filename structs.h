#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct DonorHistoryEntry{
    char* campaignName; 
    double donationAmount;             
} DonorHistoryEntry;


typedef struct CampaignHistoryEntry{
    char* donorName; 
    double donationAmount;           
} CampaignHistoryEntry;


typedef struct donor{
    char* name;                 
    double wallet;                             
    DonorHistoryEntry* history; 
    int historyCount;                      
} donor;


typedef struct campaign {
    char* name;                 
    double goal;                               
    double currentSum;                        
    CampaignHistoryEntry* history;
    int historyCount;    
} campaign;


typedef struct donorDB
{
    donor DB[10000];
    int donorCount;

}donorDB;

typedef struct campaignDB
{
    campaign DB[1000];
    int campaignCount;

}campaignDB;



#endif 

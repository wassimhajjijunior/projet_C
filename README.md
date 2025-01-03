Donor and Campaign Management Application

This is a C-based application designed to manage donors and fundraising campaigns effectively.

Features:
    Add Campaigns: Create fundraising campaigns with specific goals and track their progress.
    Add Donors: Register donors with wallet balances to manage donations.
    Make Donations (Donor's Perspective): Allows donors to contribute to campaigns.
    Acquire Donations (Charity Perspective): Automatically matches the wealthiest donor with the campaign needing the most help based on current progress.
    Display Information: View comprehensive databases of campaigns and donors, including their histories.
    
Example Inputs and Outputs
Adding Campaigns:
  How many campaigns do you want to add?
  2
  Enter campaign name: EducationFund
  Enter goal amount: 1000
  Enter current sum: 200
  Enter campaign name: HealthCare
  Enter goal amount: 500
  Enter current sum: 100

Adding Donors:
  How many donors do you want to add?
  2
  Enter donor name: Alice
  Enter donor wallet balance: 300
  Enter donor name: Bob
  Enter donor wallet balance: 150

  Printing Campaign Database:
  Campaign Database:
    Campaign Name: EducationFund
    Goal: 1000.00
    Current Sum: 200.00
  -----------------------
    Campaign Name: HealthCare
    Goal: 500.00
    Current Sum: 100.00
  -----------------------

Making a Donation:
  How much do you want to donate?:
  250
  Donation successful!
  
  Printing Donor 0's History:
  Donor Name: Alice
  Wallet Balance: 50.00
  Donation History:
    Campaign: EducationFund, Amount: 250.00
  
  Printing Campaign 0's History:
  Campaign Name: EducationFund
  Goal: 1000.00, Current Sum: 450.00
  Donation History:
  Donor: Alice, Amount: 250.00

Acquiring Donation (Charity's Perspective):
  How much do you want to donate?:
  150
  Donation successful!
  
  Updated Campaign Database:
  Campaign Database:
  Campaign Name: EducationFund
  Goal: 1000.00
  Current Sum: 600.00
  -----------------------
  Campaign Name: HealthCare
  Goal: 500.00
  Current Sum: 250.00
  -----------------------
  
  Updated Donor Database:
  Donor Database:
  Donor Name: Alice
  Wallet Balance: 50.00
  -----------------------
  Donor Name: Bob
  Wallet Balance: 0.00
  -----------------------

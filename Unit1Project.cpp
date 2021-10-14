#include <iostream>
#include <math.h>
#include <condition_variable>
#include <stdlib.h>

using namespace std;


float areaToPaint(float length, float width, float height, int windows, int doors)
{
    return ((length * width * 2) + (length * height * 4) + (width * height * 4)) - ((9 * windows) + (16 * doors));
}

float roundMoney(float dollarAmount)
{
    return (ceil(((dollarAmount) * 100)) / 100);
}

void receipt(float amountOfPaint, int preTaxOfPaint, float postTaxOfPaint, int hoursOfWork, float feeOfWork)
{
    cout << "\n\n--------------------------------------------------";
    cout << "\n|    \n|    " << "The Amount Of Paint Needed Will Be:\n|      " << amountOfPaint << " Square Feet";
    cout << "\n|    \n|    " << "Total Pre-Tax Price Of Paint:\n|      " << preTaxOfPaint << "$";
    cout << "\n|    \n|    " << "Total Post-Tax Price Of Paint:\n|      " << postTaxOfPaint << "$";
    cout << "\n|    \n|    " << "Time Required To Paint The Room:\n|      " << hoursOfWork << " Hours";
    cout << "\n|    \n|    " << "The Fee Of The Work Needed Will Be:\n|      " << feeOfWork << "$";
    cout << "\n--------------------------------------------------";
}


int main()
{
    system("Color D0");
    //VARIABLES
    string roomName;
    float length;
    float width;
    float height;
    int windows;
    int doors;
    int bucketPrice;
    float amountOfPaint;
    int preTaxOfPaint;
    const float tax = 0.13;
    float postTaxOfPaint;
    float rateOfWorkPerHour;
    float priceOfWork;
    float hoursOfWork;
    float feeOfWork;
    long long int tenDigitNumber;

    
    //INPUTS
    cout << "Please Enter The Name Of The Room:\n";
    cin >> roomName;
    cout << "\nPlease Enter The Length Of The Room In Feet(Imperial Measurements):\n";
    cin >> length;
    cout << "\nPlease Enter The Width Of The Room In Feet(Imperial Measurements):\n";
    cin >> width;
    cout << "\nPlease Enter The Height Of The Room In Feet(Imperial Measurements):\n";
    cin >> height;
    cout << "\nPlease Enter The Amount Of Windows In The Room:\n";
    cin >> windows;
    cout << "\nPlease Enter The Amount Of Doors In The Room:\n";
    cin >> doors;
    cout << "\nPlease Enter The Price Of The Paint Per Bucket(Round Up To The Nearest Integer) You Are Using:\n";
    cin >> bucketPrice;
    cout << "\nPlease Enter The Rate At Which Paint Will Be Applied(# Of Square Feet Every Hour):\n";
    cin >> rateOfWorkPerHour;
    cout << "\nPlease Enter The Price Of The Work Per Hour:\n";
    cin >> priceOfWork;


    //CALCULATIONS
    amountOfPaint = areaToPaint(length, width, height, windows, doors);
    preTaxOfPaint = ceil(bucketPrice * amountOfPaint);


        //PAINT
    if ((preTaxOfPaint % bucketPrice) == 0) {
    }
    else {
        preTaxOfPaint = (bucketPrice - (preTaxOfPaint % bucketPrice)) + preTaxOfPaint;
    }
    postTaxOfPaint = ((preTaxOfPaint * tax) + preTaxOfPaint);
    postTaxOfPaint = roundMoney(postTaxOfPaint);



        //HOURS
    hoursOfWork = (round((amountOfPaint / rateOfWorkPerHour) * 2) / 2);


        //FEE OF HOURS
    feeOfWork = (priceOfWork * hoursOfWork);
    feeOfWork = roundMoney(feeOfWork);
    

    //OUTPUT
    receipt(amountOfPaint, preTaxOfPaint, postTaxOfPaint, hoursOfWork, feeOfWork);

    cout << "\n\nPlease Enter Any 10 Digit Number For Verification:\n";
    cin >> tenDigitNumber;
    cout << "\nVerification Number Is:\n" << tenDigitNumber;
}

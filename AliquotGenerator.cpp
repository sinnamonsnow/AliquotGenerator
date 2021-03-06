#include <iostream>
#include <string>
using namespace std;

/**
* Computes the aliquot sum of the specified number
* @param num an integer
* @return the aliquot sum of the specified number
* if it is positive; otherwise, -1;
*/
long rSigma(long num)
{
	long sum=0;
	if(num<1)
		return -1;
	else
		{
		for (int i = 1; i <= num/2; i++)
		{
			if (num % i == 0)
				sum += i;
		}
		return sum;
		}
}
/**
* Generates the string representation of a series whose terms
* are increasing and consist of proper divisors of the specified number.
* @param num an integer
* @return a string representation of the series when num is
* greater than 1, "0" when num is 1; otherwise "nan"
*/
string genRSigSeries(long num)
{
	string series=" = ";
	if(num<=0)
		return "nan";
	if (num==1)
		return "0";
	if (rSigma(num)==1)
		return series;
	series+="1";
	for (int i = 2; i <= num/2; i++)
	{
		if (num % i == 0)
			series+=( " + " + to_string(i));
	}
	series+=" = ";
	return series;
}
/**
* Generates the aliquot sequence of a number and determines the
* length of the sequence.
* @param num an integer
* @param sequence the aliquot sequence of the specified number when
* num is positive; otherwise "nan".
* @param length the length of the aliquot sequence of the specified
* number when num is positive; otherwise 0
*/
void aliquot(long num, string& sequence, long& length)
{
	sequence=to_string(num);
	length=1;
	while(num>0)
	{
		sequence+=(", "+to_string(rSigma(num)));
		num=rSigma(num);
		length++;
	}

	return;
}
int main() {
	long int1,int2,leng=2;
	string sequen;
	cout<<"Enter a positive integer for its classification -> ";
	cin>>int1;
	if (int1<1)
		cout<<"The input must be a positive integer."<<endl;
	else
	{
		cout<<"s("<<int1<<")"<<genRSigSeries(int1)<<rSigma(int1)<<endl;
		cout<<"s("<<int1<<")";
		if (rSigma(int1)==int1)
		{
			cout<<" = "<<int1<<endl;
			cout<<int1<<" is a perfect number."<<endl;
		}
		else if (rSigma(int1)<int1)
		{
		cout<<" < "<<int1<<endl;
		cout<<int1<<" is a deficient number."<<endl;
		}
		else
		{
			cout<<" > "<<int1<<endl;
			cout<<int1<<" is an abundant number."<<endl;
		}
	}
	cout<<"\nEnter two positive integers -> ";
	cin>>int1>>int2;
	if (int1<0||int2<0||int1==int2)
		cout<<"ERROR: The inputs must be distinct positive integers."<<endl;
	else
	{
		cout<<"?amicable("<<int1<<","<<int2<<") = ";
		if (rSigma(int1)==int2&&rSigma(int2)==int1)
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
		cout<<"s("<<int1<<")"<<genRSigSeries(int1)<<rSigma(int1)<<endl;
		cout<<"s("<<int2<<")"<<genRSigSeries(int2)<<rSigma(int2)<<endl;
	}
	cout<<"\nEnter an imperfect positive integer -> ";
	cin>>int1;
	if (rSigma(int1)==int1)
		cout<<"ERROR: The input must be an imperfect positive integer.";
	else
		aliquot(int1,sequen,leng);
	cout<<"aliquot{"<<int1<<"} = "<<sequen<<endl;
	cout<<"length: "<<leng;
	return 0;
}

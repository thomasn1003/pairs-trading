#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>


//returns the sum of a vector
double sum(std::vector<double> stock)
{
    double FullPrice = 0.0;
    for (int i = 0; i < stock.size(); i++)
    {
        FullPrice += stock[i];
    }
    return FullPrice;
}



//returns the mean of a vector
double mean(std::vector<double> stock)
{

    return sum(stock) / stock.size();
}



//returns maximum value
double maximum(std::vector<double> stock) {
    return *std::max_element(stock.begin(), stock.end());
}

double minimum(std::vector<double> stock) {
    return *std::min_element(stock.begin(), stock.end());
}

double range(std::vector<double> stock) {
    return maximum(stock) - minimum(stock);
}






//returns squred of the vector values
double sqsum(std::vector<double> stock)
{
    double sqr = 0;
    for (int i = 0; i < stock.size(); i++)
    {
        sqr += pow(stock[i], 2);
    }
    return sqr;
}



//returns the standard deviation
double stdev(std::vector<double> stock)
{
    double size = stock.size();
    return pow(sqsum(stock) / size - pow(sum(stock) / size, 2), 0.5);
}

double variance(std::vector<double> stock)
{
    double size = stock.size();
    return (sqsum(stock) / size - pow(sum(stock) / size, 2));
}




//returns pearsons coeffient correlation value
std::vector<double> operator-(std::vector<double> a, double b)
{
    std::vector<double> retvect;
    for (int i = 1; i < a.size(); i++)
    {
        retvect.push_back(a[i] - b);
    }
    return retvect;
}

std::vector<double> operator*(std::vector<double> a, std::vector<double> b)
{
    std::vector<double> retvect;
    for (int i = 0; i < a.size(); i++)
    {
        retvect.push_back(a[i] * b[i]);
    }
    return retvect;
}

double pearsoncoeff(std::vector<double> stock1, std::vector<double> stock2)
{
    return sum((stock1 - mean(stock1)) * (stock2 - mean(stock2))) / (stock1.size() * stdev(stock1) * stdev(stock2));
}




int main()
{
    // Opens APPLE stock csv file
    std::string myFile1 = "GOOGL.csv";
    std::ifstream aapl;
    aapl.open(myFile1);

    std::vector<double> applestock;

    std::string line = "";
    std::getline(aapl,line);
    
    while (std::getline(aapl, line))
    {
        std::string aapl_date;
        double aapl_open;
        std::string aapl_high;
        std::string aapl_low;
        std::string aapl_close;
        std::string aapl_adjclose;
        std::string aapl_volume;
        std::string tempstring1 = "";

        std::stringstream inputString(line);

        // getting the open values of the stock
        std::getline(inputString, aapl_date, ',');

        // getline(inputString, open, ',');
        std::getline(inputString, tempstring1, ',');
        aapl_open = atof(tempstring1.c_str());

        std::getline(inputString, aapl_high, ',');
        std::getline(inputString, aapl_low, ',');
        std::getline(inputString, aapl_close, ',');
        std::getline(inputString, aapl_adjclose, ',');
        std::getline(inputString, aapl_volume, ',');

        applestock.push_back(aapl_open);

        line = "";
    }

    






    // Opens MICROSOFT stock csv file
    std::string myFile2 = "MSFT.csv";
    std::ifstream msft;
    msft.open(myFile2);

    std::vector<double> msftstock;
    
    std::string line2 = "";
    std::getline(msft,line2);

    while (std::getline(msft, line2))
    {
        std::string msft_date;
        double msft_open;
        std::string msft_high;
        std::string msft_low;
        std::string msft_close;
        std::string msft_adjclose;
        std::string msft_volume;
        std::string tempstring2 = "";

        std::stringstream inputString(line2);

        // getting the open values of the stock
        std::getline(inputString, msft_date, ',');

        // getline(inputString, open, ',');
        std::getline(inputString, tempstring2, ',');
        msft_open = atof(tempstring2.c_str());

        std::getline(inputString, msft_high, ',');
        std::getline(inputString, msft_low, ',');
        std::getline(inputString, msft_close, ',');
        std::getline(inputString, msft_adjclose, ',');
        std::getline(inputString, msft_volume, ',');

        msftstock.push_back(msft_open);

        line2 = "";
    }
    
   
    std::cout << "Calculating Pairs Trading Algorithms for Google and Microsoft" << std::endl;
    std::cout << "Mean: " << "Google(" << mean(applestock) << ") and Microsoft(" << mean(msftstock) << ")\n";
    std::cout << "Maximum: " << "Google(" << maximum(applestock) << ") and Microsoft(" << maximum(msftstock) << ")\n";
    std::cout << "Minimum: " << "Google(" << minimum(applestock) << ") and Microsoft(" << minimum(msftstock) << ")\n";
    std::cout << "Range " << "Google(" << range(applestock) << ") and Microsoft(" << range(msftstock) << ")\n";
    std::cout << "Standard Deviation: " << "Google(" << stdev(applestock) << ") and Microsoft(" << stdev(msftstock) << ")\n";
    std::cout << "Variance: " << "Google(" << variance(applestock) << ") and Microsoft(" << variance(msftstock) << ")\n";
    std::cout << "Coeffient Correlation: " << pearsoncoeff(applestock,msftstock);
    std::cout << pearsoncoeff(applestock, msftstock) << std::endl;


    aapl.close();
    msft.close();
    return 0;
}

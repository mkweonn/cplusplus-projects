/* portfolio.cpp
* This program .
* @author Michelle Kweon
* mkweon@usc.edu
* ITP 365, Fall 2023
*/

#include "portfolio.h"

// StockPortfolio default constructor
StockPortfolio::StockPortfolio(){
//    Money mCents = 0;
//    Money mPurchasePrice = 0;
//    Money mCurrentPrice = 0;// Sets the money member variables to empty
    mStocks.clear(); // clear member variable
}

// Doesn't check if the stock already exists will overwrite the old stock if it's in there
void StockPortfolio::addStock(Stock inStock){
    std::string key = inStock.getSymbol(); // get symbol of stock
    mStocks[key] = inStock; // add stock to map
}

bool StockPortfolio::containsStock(std::string inSymbol) {
    if(mStocks.count(inSymbol) !=0) { // check to see key occurs at least once
        return true;
    }
    else {
        return false;
    }
}

Stock& StockPortfolio::operator[](std::string inSymbol) {
    return mStocks[inSymbol]; // return value attached to key
}

Money StockPortfolio::getTotalValue() const {
    Money totalValue;
    for (const auto& item : mStocks) { // loop through stock map/portfolio
        totalValue = totalValue + (item.second.getCurrPrice() * item.second.getNumShares()); // add all together to get net-worth of all stocks in portfolio
    }
    return totalValue;
}

Money StockPortfolio::getOrigValue() const {
    Money origValue;
    for (const auto& item : mStocks) { // loop through stock map/portfolio
        origValue = origValue + (item.second.getPurPrice() * item.second.getNumShares()); // add all together to get purchase price of all stocks in portfolio
    }
    return origValue;
}

Money StockPortfolio::getProfit() const {
   
    Money profit;
    for (const auto& item : mStocks) { // loop through stock map/portfolio
        profit = profit + (item.second.getChange() * item.second.getNumShares()); // add all together to get change price price of all stocks in portfolio
    }
//    Money profit = getTotalValue() - getOrigValue();
    return profit;
}

std::vector<std::string> StockPortfolio::getAlphaList() {
    std::vector<std::string> alphaList; // vector with alphabetically sorted stock symbols
    
    for (const auto& item : mStocks) { // each item in stock portfolio
        alphaList.push_back(item.first); // add each stock symbol (key of stock portfolio map) into vector
    }
    
    for (int i=0; i < alphaList.size()-1; i++) { // loop/go through entire vector to find smallest element from i to total vector size and compare each to sort
        
        // start at index i because everything before i has been sorted already
        int minIndex = i;
        for (int next = i + 1; next <alphaList.size(); next++){
            // is this smaller than the current smallest?
            if (alphaList[next] < alphaList[i]){ // compare characters to determine alphabetical rank

                // swap the smallest value with the value at index i
                std::string temp = alphaList[i];
                alphaList[i] = alphaList[next];
                alphaList[next] = temp;
            }
        }
    }
    return alphaList;
}

std::vector<std::string> StockPortfolio::getValueList() {
//    std::vector<Stock> stockList; // vector of stocks
    std::vector<std::string> valueList; // vector with sorted stock symbols based on decreasing current value

    for (const auto& item : mStocks) {
        valueList.push_back(item.first); // add all stocks in portfolio in vector
    }
    
    for (int i=0; i < valueList.size(); i++) { // loop/go through entire vector to find smallest element from i to total vector

        int largestIndex = i; // make i largest index to begin
        std::string largest = valueList[i]; // make the first one largest to begin

        for (int n = i + 1; n < valueList.size(); n++){
            if (mStocks[largest].getCurrPrice() < (mStocks[valueList[n]]).getCurrPrice()){ // compare current prices
                // grab largest index and value;
                largestIndex = n;
                largest = valueList[n];
            }
        }
        
        // swap
        valueList[largestIndex] = valueList[i]; //valueList[n]
        valueList[i] = largest; // switched in for loop if it is smaller
    }
    return valueList; // vector with stock symbols
}

// Summary:
//        The stock symbols will be sorted by (decreasing) change
//          This is by individual stock difference -- not all the stocks of a company
std::vector<std::string> StockPortfolio::getDiffList() {
//    std::vector<Stock> changeList; // vector with profit value of stocks
    std::vector<std::string> diffList; // vector with stock symbols sorted based on change in price (decreasing)
    
    for (const auto& item : mStocks) {
        diffList.push_back(item.first);
    }
    
    for (int i=0; i < diffList.size()-1; i++) { // loop/go through entire vector to find smallest element from i to total vector size
        int largestIndex = i; // make i largest index to begin
        std::string largest = diffList[i]; // make the first one largest to begin
        
        for (int n = i + 1; n < diffList.size(); n++){
            if(mStocks[largest].getChange() < (mStocks[diffList[n]]).getChange()){ // compare change values
                largestIndex = n;
                largest = diffList[n];
            }
        }
        // swap
        diffList[largestIndex] = diffList[i];
        diffList[i] = largest; // switched in for loop if it is smaller
    }
    
    return diffList; // vector with stock symbols
}


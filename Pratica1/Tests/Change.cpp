/*
 * Change.cpp
 */

#include "Change.h"
using namespace std;
/*
 * Alínea a)
 *  Comeca-se por considerar as moedas de maior valor (ultima moeda de coinValues)
 *  adicionando-se ao valor de troco, se o valor adicionado levar a um troco maior que
 *  o necessário, retira-se o que foi adicionado e usa-se as moedas de segundo maior
 *  valor e assim sucessivamente ate se atingir o valor de troco. (nao da certo)
 */

/*
 * Alínea b) e c) no caderno
 */

vector <int> minCoins(int i, int k, int *coinValues){
    vector <int> result;
    for (int x = i-1; x >= 0; x--){
        int num = k/coinValues[x];
        for (int j = 0; j < num; j++) result.push_back(coinValues[x]);
        k %= coinValues[x];
    }
    return result;
}

string calcChange(int m, int numCoins, int *coinValues)
{
    string result = "";
    vector<int> min = minCoins(numCoins, m, coinValues);
    for (int i = 1; i <= numCoins; i++){
        if (minCoins(i,m,coinValues).size() < min.size() && accumulate(min.begin(), min.end(),0) == m) min = minCoins(i,m,coinValues);
    }
    if (accumulate(min.begin(), min.end(),0) != m) result = "-";
    for (int x: min){
        result += (to_string(x) + ";");
    }
    return result;
}


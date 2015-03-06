
#include <iostream>
#include <list>

int value = 0;
int weight = 1;

int ** fillTable(int n, int cap, int ** items);
void backtrace(int n, int cap, int ** items, int ** table);

int main(){
    float f;
    int n;

    while(std::cin >> f ){
        int cap = (int) f;
        std::cin >> n;

        int ** items;
        items = new int*[n];
        for(int i=0; i < n; i++){
            items[i] = new int[2];
            for (int j=0; j < 2; j++){
                items[i][j] = 0;
            }
        }

        for(int i=0; i < n; i++){
            //Weight
            std::cin >> items[i][value];
            //Value
            std::cin >> items[i][weight];
        }

        int ** table = fillTable(n,cap,items);

        backtrace(n,cap,items,table);
        for(int i=0; i < n+1; i++){
            for(int j=0; j < cap+1; j++){
                std::cout << table[i][j] << " ";
            }
            std::cout << "\n";
        }
    delete items;
    delete table;
    }
    return 0;
}

int ** fillTable(int n, int cap, int ** items){
    int ** table;
    table = new int*[n+1];
    for(int i=0; i < n+1; i++){
        table[i] = new int[cap+1];
        for(int j=0; j < cap+1; j++){
            table[i][j] = 0;
        }
    }

    // Where i is the current item
    for(int i=1; i < n+1; i++){
        //where j is the current cap
        for(int j=1; j < cap+1; j++){
            int cW = items[i-1][weight];
            int cV = items[i-1][value];
            //if item fits in knapsack
            if(cW <= j){
                //This represents not taking the item
                //No other items fit
                if(table[i-1][j] == 0){
                    table[i][j] = items[i-1][value];
                //Another item fits!
                }else{
                    //It's better not to take the new item
                    if(table[i-1][j] > (table[i-1][j-cW]+cV) ){
                        table[i][j] = table[i-1][j];
                    }else{
                        table[i][j] = (table[i-1][j-cW]+cV);
                    }
                }
            //The item doesn't fit
            }else{
                //Previous best
                table[i][j] = table[i-1][j];
            }


        }
    }
    return table;
}

void backtrace(int n, int cap,int ** items, int ** table){
    //Current cap
    std::list<int> taken;
    int j = cap;
    //Current item
    for(int i=n; i > 0; i--){
            if(table[i][j] != table[i-1][j]){
                taken.push_front(i-1);
                j = j-items[i-1][weight];
            }
    }

    std::cout << taken.size() << '\n';
    for (std::list<int>::iterator it=taken.begin(); it != taken.end(); ++it)
        std::cout  << *it << ' ';

    std::cout << '\n';
    return;
}
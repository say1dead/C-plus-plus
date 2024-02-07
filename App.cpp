//
// Created by kochu on 07.02.2024.
//

#include "AddToSet.h"
#include "CheckIfIn.h"
#include "Delete.h"
#include "IntersectionOfTwo.h"
#include "UnionOfTwo.h"

int StartOs(){
    int n;
    while(true){
        cout << "\nEnter choice:";
        cout << "\n1. Check.\n2. Add.\n3. Delete.\n4. Intersection.\n5. Union.\n6. End.\nChoice:";
        cin >> n;
        switch(n){
            case(1):StartCheckIfIn();
                break;
            case(2):StartAddToSet();
                break;
            case(3):StartDeleteElement();
                break;
            case(4):StartIntersectionOfTwo();
                break;
            case(5):StartUnionOfTwo();
                break;
            case(6):return 0;
        }
    }
}

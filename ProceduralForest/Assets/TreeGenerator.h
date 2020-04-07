//
// Created by hyperion on 2020-04-05.
//

#ifndef INC_371PROCEDURALFOREST_TREEGENERATOR_H
#define INC_371PROCEDURALFOREST_TREEGENERATOR_H

#include <Entities/Tree.h>
#include "Entity.h"

class TreeGenerator {
public:
    static Tree* generateTree(vec3);
private:
    static void generateTrunk(Tree&, int);
    static void generateLeaves(Tree&, int, vec3);
    static float euclidianNorm(vec3, vec3);
    static bool inSphere(vec3, vec3, float);
    static int computeNumberInX(vec3 center, float radius, int index, int increment);
    static int computeNumberInZ(vec3 position, vec3 center, float radius, int index, int increment);
};


#endif //INC_371PROCEDURALFOREST_TREEGENERATOR_H
//
// Created by Steven Smith on 2020-04-05.
//
// Modified by RemineralizedWater(Michael Rowe) on 2020-04-08
// Student ID: 26101267
//

#ifndef INC_371PROCEDURALFOREST_WORLD_H
#define INC_371PROCEDURALFOREST_WORLD_H

#include "Transform.h"
#include "Entity.h"
#include <vector>
#include <map>
#include "glm/glm.hpp"
#include "Tree.h"
#include "Terrain.h"

typedef std::pair<int, std::vector<Tree*>> terrainPair;
typedef std::map<int, std::vector<Tree*>> terrainMap;

class World {
public:
    World();
    World(const World&);
    ~World();
    void Draw();
    void AddEntities(Entity*);
    void RemoveEntity(int index);
    Entity* GetEntity(int index){return world_entities[index];}
    void Update();
    static World& getCurrent();
    Transform getTransform(){return worldTransform;};
    void ProcedurallyGenerateWorld();
private:
    Transform worldTransform;
    std::vector<Entity*> world_entities;
    static World current;
    terrainMap terrain_mapping;
    void GenerateForest(float, Terrain terrain);
    bool placeTree(float, int, Tree*, int, int);

};


#endif //INC_371PROCEDURALFOREST_WORLD_H
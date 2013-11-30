//
//  GameManager.cpp
//  BattlezoneClone
//
//  Created by Adam Cumiskey on 11/26/13.
//  Copyright (c) 2013 Adam Cumiskey. All rights reserved.
//

#include "GameManager.h"
#include "TerrainObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"


#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

GameManager::GameManager()
{
    // Empty Constructor
}

void GameManager::initializeGame(int numOfTerrainObjs, int gameArea)
{
    generateObjects(numOfTerrainObjs, gameArea);
    createEnemy();
    initializePlayer();
}

void GameManager::updateGame()
{
    _player->updateCamera();

    drawGround();
    
    std::vector<TerrainObject *>::iterator it = _terrainObjects.begin();
    while (it != _terrainObjects.end()) {
        TerrainObject object = *_terrainObjects.at(it - _terrainObjects.begin());
        object.renderObject();
        it++;
    }
    
    _enemy->renderEnemy();
    if (firing) {
        _playerProjectile->renderProjectile();
    }
}

void GameManager::animateGame()
{
    _enemy->aim(_player->getPosition());
    
    if (firing) {
        _playerProjectile->move();
        // check the distance
        if (MovableObject::distance(*_player, *_playerProjectile) > 100) {
            removeProjectile(_playerProjectile);
        }
    }
}

void GameManager::input(unsigned char key)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            _player->MoveForward(-.5);
            break;
        case 'a':
            _player->RotateY(5.0);
            break;
        case 's':
            _player->MoveForward(.5);
            break;
        case 'd':
            _player->RotateY(-5.0);
            break;
        case ' ':
            fire();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

#pragma mark - Player Manager
void GameManager::initializePlayer()
{
    _player = new Player(0, 1, 0);
}

void GameManager::fire()
{
    firing = true;
    _playerProjectile = new Projectile(_player->getPosition(),
                                 _player->getDirection(),
                                 _player->getRotation());
}

void GameManager::removeProjectile(Projectile *_projectile)
{
    if (_playerProjectile != NULL) {
        delete _playerProjectile;
    }
    firing = false;
}

#pragma mark - Enemy Manager
void GameManager::createEnemy()
{
    _enemy = new Enemy(1, .5, -5);
    _enemy->changeAIToState(AI_MOVE);
}

#pragma mark - Terrain Manager
void GameManager::generateObjects(int n, int gridSize)
{
    for (int i = 0; i < n; i++) {
        
        // Generate random size between 1 and 3
        GLdouble size = (float)(rand() % 3);
        
        // generate random x and z positions within the grid
        GLfloat x = (rand() % gridSize) - (gridSize/2);
        GLfloat z = (rand() % gridSize) - (gridSize/2);
        
        // set the y to touch the ground
        GLfloat y = 0;
        
        // Generate a type
        TerrainType type = rand() % 2;
        
        TerrainObject *object = new TerrainObject(x,
                                                  y,
                                                  z,
                                                  size,
                                                  type);
        _terrainObjects.push_back(object);
    }
}

void GameManager::drawGround()
{
    // Draw 4 triangles from the origin with
    // 4 unit vertecies located at infinity
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.75, 0.0);
    glVertex4f(0, 0, 0, 1);
    glVertex4f(1, 0, 0, 0);
    glVertex4f(0, 0, 1, 0);
    glVertex4f(-1, 0, 0, 0);
    glVertex4f(0, 0, -1, 0);
    glVertex4f(1, 0, 0, 0);
    glEnd();
}

#pragma mark - Destructor
GameManager::~GameManager()
{
    delete _enemy;
    delete _player;
    delete _playerProjectile;
}
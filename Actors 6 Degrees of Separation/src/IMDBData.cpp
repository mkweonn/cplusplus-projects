// ITP 365 Spring 2023
// HW10 – 6 Degrees of Separation
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "IMDBData.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

IMDBData::IMDBData(const std::string& fileName)
{
    // load the inputted .list file that contains actors
    std::ifstream inputFile(fileName);
    
    // check if file opened
    if (!inputFile.is_open()) {
        // exception
        throw std::invalid_argument("File \"" + fileName + "\" didn't open successfully.");
    }
    
    // string to hold actor name
    std::string actor;
    // string to hold lines
    std::string line;
    // vector to hold movies
    std::vector<std::string> movies;
    // string for movie name
    std::string moviesStr;
    
    // load contents by parsing out text file
    while (!inputFile.eof()) { // continue looping as long as it is not the end of file
        // read in line
        std::getline(inputFile, line);
        
        // actor name is first line of file
        if(line[0] != '|') {
            // if it doesn't have a bar, it is a actor
            actor = line;
            // clear to make sure it resets for every actor
            movies.clear();
        }
        // get movies
        else if(line[0] == '|') {
            // start at 1 to not get '|'
            moviesStr = line.substr(1);
            // add movie to vector
            movies.push_back(moviesStr);
        }
        
        // populates data into hash map where actor correlated with list of movies
        mActorsToMoviesMap[actor] = movies;
    }
    
    // constructs the graph with actor relationships
    for(auto& movies : mActorsToMoviesMap) {
        // “reverse” map where every movie is associated with an actor to get mMoviesToActorsMap
        reverseMap(movies.first, mActorsToMoviesMap[movies.first]);
    }
    
    // close file
    inputFile.close();
}

void IMDBData::reverseMap(const std::string& actorName, const std::vector<std::string>& movies)
{
    // loop through all movies in vector
    for(int i=0; i < movies.size(); i++) {
        // if mMoviesToActorsMap already contains the movie in question
        if(mMoviesToActorsMap.find(movies[i]) != mMoviesToActorsMap.end()) {
            // check if actor is already in the map vector
            bool actorFound = false;
            for(const auto& actor : mMoviesToActorsMap[movies[i]]) {
                if(actor == actorName) {
                    actorFound = true;
                    break;
                }
            }
            
            // only add if it isn't already added to avoid repeats
            if(!actorFound) {
                //add actorName to that movie’s associated vector
                mMoviesToActorsMap[movies[i]].push_back(actorName);
            }
        }
        // otherwise, add an entry in mMoviesToActorsMap that associates the movie with a vector that, for now, only contains actorName
        else {
            std::vector<std::string> actorVec;
            actorVec.push_back(actorName);
            mMoviesToActorsMap[movies[i]] = actorVec;
        }
    }
}

const std::vector<std::string>& IMDBData::getMoviesFromActor(const std::string& actorName)
{
    // if map contains actor
    if(mActorsToMoviesMap.find(actorName) != mActorsToMoviesMap.end()) {
        // return vectors with all their movies (value of map)
        return mActorsToMoviesMap[actorName];
    }
    // if map does not contain the actor
    else {
        return sEmptyVector;
    }
}

const std::vector<std::string>& IMDBData::getActorsFromMovie(const std::string& movieName)
{
    // if map contains movie
    if(mMoviesToActorsMap.find(movieName) != mMoviesToActorsMap.end()) {
        // return all the actors in movie
        return mMoviesToActorsMap[movieName];
    }
    // if map does not contain the movie
    else {
        return sEmptyVector;
    }
}

void IMDBData::createGraph()
{
    // for each movie in the map
    for(auto& movie : mMoviesToActorsMap) {
        // get the name (key of map)
        const std::string& movieName = movie.first;
        // get actors in the movie
        // movie name is used to connect each actor with every other actor in value
        const std::vector<std::string>& actorsList = movie.second;

        // make edges
        for(int i=0; i < actorsList.size(); i++) {
            // create/point to a node
            ActorNode* firstActor = mGraph.getActorNode(actorsList[i]);
            // get adjacent node
            for(int j=i+1; j < actorsList.size(); j++) {
                ActorNode* secondActor = mGraph.getActorNode(actorsList[j]);
                // create the edge to populate map
                mGraph.createActorEdge(firstActor, secondActor, movieName);
            }
        }
    }
}

std::string IMDBData::findRelationship(const std::string& fromActor, const std::string& toActor)
{
    // string stream to output results of BFS search
    std::stringstream ss;
    
    // check that the two actors are in the graph
    if(!mGraph.containsActor(fromActor) || !mGraph.containsActor(toActor)) {
        if(!mGraph.containsActor(fromActor)) {
            ss << fromActor << " is unknown!" << std::endl;
        }
        if(!mGraph.containsActor(toActor)) {
            ss << toActor << " is unknown!" << std::endl;
        }
        return ss.str();
    }
    
    // BFS implementation to find relationship between two actors
    else {
        // get pointer to first node
        ActorNode* firstActor = mGraph.getActorNode(fromActor);
        // get second node
        ActorNode* secondActor = mGraph.getActorNode(toActor);
        
        ActorNode* current = nullptr;
        bool pathFound = false;
        
        // 1. create a queue of ITPGraphNode*
        std::queue<ActorNode*> queueActors;
        // and enque the node we're starting from
        queueActors.push(firstActor);
        
        // 2. while the BFS queue is not empty...
        while(!queueActors.empty()) {
            // save the front of ITPGraphNode* in currentNode
            current = queueActors.front();
            // deque the front of ITPGraphNode*
            queueActors.pop();
            // if currentNode == targetNode, we found a path!
            if(current == secondActor) {
                pathFound = true;
            }
            
            // otherwise if currentNode’s visited bool is false…
            if(!current->mIsVisited) {
                // set each ActorNode’s mIsVisited variable as you visit it to make sure you don’t revisit the same nodes
                // visit currentNode by setting currentNode visited to true
                current->mIsVisited = true;
                // loop through currentNode’s adjacency list (vector of Edges) and if the visited flag is false…
                for(Edge& edge : current->mEdges) {
                    if(edge.mOtherActor->mIsVisited == false) {
                        // if the adjacent node path has a size of 0…
                        if(edge.mOtherActor->mPath.size() == 0) {
                            // set the adjacent node’s path equal to currentNode’s path
                            edge.mOtherActor->mPath = current->mPath;
                            // push_back adjacent nodes’s name to adjacent node’s path
                            edge.mOtherActor->mPath.push_back(PathPair(edge.mMovieName, edge.mOtherActor->mName));
                        }
                        
                        // enqueue the adjacent node
                        queueActors.push(edge.mOtherActor);
                    } // end of first if statement in for loop
                } // end of for loop
            } // end of if(!current->mIsVisited)
        } // end of while loop
        
        if(pathFound) {
            ss << "Found a path! ";
            ss << "(" << secondActor->mPath.size() << " hops)" << std::endl;
            ss << fromActor << " was in..." << std::endl;
            //        for(PathPair& pair : current->mPath) {
            //            if(pair.getActorName() == toActor)  {
            //              ss << pair.getMovieName() << " with " << pair.getActorName() << std::endl;
            //            }
            //            else {
            //              ss << pair.getMovieName() << " with " << pair.getActorName() << " who was in... " << std::endl;
            //            }
            //        }
            for(int i=0; i < secondActor->mPath.size(); i++) {
                // last output
                if(i == secondActor->mPath.size() - 1) {
                    ss << secondActor->mPath[i].getMovieName() << " with " << secondActor->mPath[i].getActorName() << std::endl;
                }
                else {
                    ss << secondActor->mPath[i].getMovieName() << " with " << secondActor->mPath[i].getActorName() << " who was in..." << std::endl;
                }
            } // end of four loop
        } // end of if(path found)
        
        // 3. if we made it here, we didn’t find a path
        else {
            ss << "Didn't find a path." << std::endl;
        }
        
        // do not remove or move the clearVisited call at the bottom of the function. It must be there or your BFS will only work once per run of the program
        mGraph.clearVisited();
        return ss.str();
        
    } // end of else from very first if - else statement
}

// Leave here! Do not edit!!!
// DO NOT REMOVE THIS LINE
std::vector<std::string> IMDBData::sEmptyVector;

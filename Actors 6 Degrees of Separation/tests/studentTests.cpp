// ITP 365 Spring 2023
// HW10 – 6 Degrees of Separation
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#include "catch.hpp"
#include "IMDBData.h"
#include <iostream>

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Student tests", "[student]") 
{
    SECTION("Bad constructor, Loading file")
    {
        {
            // check that a file with bad name doesn't open and throws error
            try {
                IMDBData imdb("input/bad$fileName.list");
                REQUIRE(false);
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                REQUIRE(true);
            }
        }
    }
    
    SECTION("Default constructor")
    {
        IMDBData imdb("input/top250.list");
        
        // check map was set correctly
        std::vector<std::string> movies1 = imdb.getMoviesFromActor("Diahnne Abbott");
    
        // checking parsing
        std::vector<std::string> expected2 = {"|Taxi Driver (1976)"};
        REQUIRE(movies1 != expected2);
        
        std::vector<std::string> expected1 = {"Taxi Driver (1976)"};
        REQUIRE(movies1 == expected1);
        
        // should return the value of map
        std::vector<std::string> movies2 = imdb.getMoviesFromActor("Leo White");
        std::vector<std::string> expected3 = {"Casablanca (1942)", "Sunrise: A Song of Two Humans (1927)" , "The Great Dictator (1940)"};
        REQUIRE(movies2 == expected3);
    }
    
    SECTION("reverseMap")
    {
        IMDBData imdb("input/top250.list");
        //        imdb.reverseMap("Leo White", actors);
        
        // this gets value from mMoviesToActorsMap
        std::vector<std::string> actors = imdb.getActorsFromMovie("The Best Years of Our Lives (1946)");
        // return the value of the map - checking vector has the actors
        std::vector<std::string> expected = {"Marek Windheim", "John Tyrrell (II)", "Ray Teal", "Stephen Soldi", "Ralph Sanford", "Harold Russell", "Suzanne Ridgway", "Minna Gombell", "Charles Halton", "Harold Miller", "William H. O'Brien", "William Newell", "Leo Penn", "Ernesto Molinari", "Ray Collins", "Caleb Peterson", "Wilbur Mack", "Joe Palma", "Fredric March", "Kenner G. Kemp", "Robert Karnes", "Michael Mauree", "Ray Hyke", "Stuart Holmes", "Erskine Sanford", "Claire Du Brey", "Earle Hodgins", "Bert Stevens", "Bert Conway", "Clancy Cooper", "Amelita Ward", "Dick Gordon", "Joyce Compton", "Tennessee Ernie Ford", "Pat Flaherty", "Teddy Infuhr", "Roman Bohnen", "Billy Engle", "Blake Edwards", "Myrna Loy", "Gene Krupa", "Jackie Jackson", "Doreen McCann", "Steve Cochran", "Sidney Clute", "Judy Wyler", "James Conaty", "Heinie Conklin", "Harry Cheshire", "Edward Earle", "Jan Wiley", "Chef Milani", "Doris June Fesetta", "Norman Phillips Jr.", "Tom Dugan", "Don Beddoe", "Mickey Roth", "Walter Baldwin", "Carol Andrews", "Lester Dorr", "Susan Mann (II)", "Dana Andrews", "Jimmy Ames", "Georgie Nokes", "Ben Erway", "Catherine Wyler", "Teresa Wright", "Louise Franklin", "Alyn Lockwood", "Mady Correll", "Ruth Sanderson", "Hal K. Dawson", "Jack Rice", "Virginia Mayo", "Cathy O'Donnell", "Thomas Martin", "Hoagy Carmichael", "Harry Gillette (II)", "Noreen Sayles", "Victor Cutler", "Georgia Kane", "Mary Arden (III)", "Roy Darmour", "Gladys George", "John Ince", "Donald Kerr", "Marlene Aames", "Howland Chamberlain", "Dean White", "Peggy McIntyre", "Michael Hall (VI)", "Dorothy Adams"};
        REQUIRE(actors.size() == 92);
        REQUIRE(actors == expected);
        
        std::vector<std::string> sEmptyVector;
        
        // returns empty vector if the map doesn't contain the movie
        std::vector<std::string> movies3 = imdb.getActorsFromMovie("Michelle's Movie (2023)");
        REQUIRE(movies3 == sEmptyVector);
        

//        for(auto& movies : mActorsToMoviesMap) {
//            // “reverse” map where every movie is associated with an actor
//            reverseMap(movies.first, mActorsToMoviesMap[movies.first]);
//        }
    }
    
    SECTION("GetMoviesFromActor") // (movies --> actors)
    {
        IMDBData imdb("input/top250.list");
        
        std::vector<std::string> movies1 = imdb.getMoviesFromActor("Al Pacino");
        std::vector<std::string> expected1 = {"Dog Day Afternoon (1975)", "Heat (1995)", "In the Name of the Father (1993)", "Scarface (1983)", "The Godfather (1972)", "The Godfather: Part II (1974)"};
        REQUIRE(movies1.size() == 6);
        // checking it returns the correct value of the map
        REQUIRE(movies1 == expected1);
        
        std::vector<std::string> movies2 = imdb.getMoviesFromActor("Lucia M. Aguirre");
        std::vector<std::string> expected2 = {"The Dark Knight Rises (2012)"};
        REQUIRE(movies2 == expected2);
        REQUIRE(movies2.size() == 1);
        
        std::vector<std::string> sEmptyVector;
        
        // returns empty vector if the map doesn't contain the actor
        std::vector<std::string> movies3 = imdb.getMoviesFromActor("Michelle Kweon");
        REQUIRE(movies3 == sEmptyVector);
    }
    
    SECTION("GetActorsFromMovie") // (actors --> movies)
    {
        IMDBData imdb("input/top250.list");
        
        std::vector<std::string> actors = imdb.getActorsFromMovie("Jurassic Park (1993)");
        // return the value of the map
        std::vector<std::string> expected = { "BD Wong", "Gerald R. Molen", "Tom Mishler", "Joseph Mazzello", "Miguel Sandoval", "Richard Kiley", "Samuel L. Jackson", "Jeff Goldblum", "Brian Smrz", "Laura Dern", "Christopher John Fields", "Adrian Escober", "Robert 'Bobby Z' Zajonc", "Greg Burson", "Dean Cundey", "Ariana Richards", "Brad M. Bucklin", "Cameron Thor", "Michael Lantieri", "Richard Attenborough", "Laura Burnett", "Martin Ferrero", "Whit Hertford", "Bob Peck", "Sam Neill", "Wayne Knight", "Lata Ryan", "Jophery C. Brown", "Gary Rodriguez"};
        REQUIRE(actors.size() == 29);
        REQUIRE(actors == expected);
        
        std::vector<std::string> sEmptyVector;
        
        // returns empty vector if the map doesn't contain the movie
        std::vector<std::string> movies3 = imdb.getActorsFromMovie("Michelle's Movie (2023)");
        REQUIRE(movies3 == sEmptyVector);
    }
    
//    SECTION("Create graph")
//    {
//        IMDBData imdb("input/top250.list");
//        std::vector<std::string> actor1 = imdb.getMoviesFromActor("Jurassic Park (1993)");
//        imdb.createGraph();
//
////        REQUIRE(imdb.containsActor("BD Wong"));
//        // edges
//    }
    
    SECTION("FindRelationship")
    {
        IMDBData imdb("input/top250.list");
        // createGraph checked based on if findRelationship works
        imdb.createGraph();
        
        std::string relationship = imdb.findRelationship("Gail Yudain", "Seguna");
        std::string output = std::string("Found a path! (6 hops)\n") + "Gail Yudain was in...\n" + "The Departed (2006) with Brian Smyj who was in...\n" + "Gladiator (2000) with Russell Crowe who was in...\n" + "L.A. Confidential (1997) with Jane Russell who was in...\n" + "Nuovo Cinema Paradiso (1988) with Simone Signoret who was in...\n" + "Les diaboliques (1955) with Charles Vanel who was in...\n" + "Le salaire de la peur (1953) with Seguna\n";
        // check outputs are the same
        REQUIRE(relationship == output);

        // check relationship without a path
        std::string relationship2 = imdb.findRelationship("Sahar Kave", "Seguna");
        std::string output2 = "Didn't find a path.\n";
        REQUIRE(relationship2 == output2);
        
        // check output for unknown actors
        std::string relationship3 = imdb.findRelationship("Kevin Bacon", "Nicki Minaj");
        std::string output3 = std::string("Kevin Bacon is unknown!\n") + "Nicki Minaj is unknown!\n";
        REQUIRE(relationship3 == output3);
        
        std::string relationship4 = imdb.findRelationship("Janet Zappala", "Laura Dern");
        std::string output4 = std::string("Found a path! (3 hops)\n") + "Janet Zappala was in...\n" + "Twelve Monkeys (1995) with Bruce Willis who was in...\n" + "Pulp Fiction (1994) with Samuel L. Jackson who was in...\n" + "Jurassic Park (1993) with Laura Dern\n";
        REQUIRE(relationship4 == output4);
        
        // check output for one unknown actor
        std::string relationship5 = imdb.findRelationship("Janet Zappala", "Nicki Minaj");
        std::string output5 = std::string("Nicki Minaj is unknown!\n");
        REQUIRE(relationship5 == output5);
    }
}

    



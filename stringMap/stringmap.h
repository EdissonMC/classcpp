/*
    String  Vs 1
    Implementation by CS106BX Stanford Book

    File: stringmap.h
    _________________
    This interface exports a simplified version of the Map class
    in which the keys and values are always strings.

*/

#ifndef _stringmap_h
#define _stringmap_h


#include <iostream>
#include <vector>


class StringMap
{
    public:
        /*
            Constructor: StringMap
            Usage: StringMap map;
            ____________________
            Initializes a new empty map that uses strings as both keys and values.
        */
            StringMap();


        /*
            Destructor : ~StringMap
            _______________________
            Frees any heap storage associated with this map
        */
            ~StringMap();


        /*
            Method: get
            Usage: string value = map.get(key);
            __________________________________
            Returns the value for key or the empty string, if key is unbound
        */
            std::string get(const std::string & key) const;

        /*
            Method: put
            Usage: map.put(key, value);
            ___________________________
            Associates key with value in this map
        */
            void put(const std::string & key,  const std::string & value);
    private:
        /*
            Type: KeyValuePair
            __________________
            This type combies a key and value into a single structure
        */
            struct KeyValuePair{
                std::string key;
                std::string value;
            };



        /*
            Instance variables
        */
            std::vector<KeyValuePair> bindings;
            
            // std::vector<int> prueba;

        /*
            Private function prototypes
        */
            int findKey(const std::string & key) const;

};




#endif
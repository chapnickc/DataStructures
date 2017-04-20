
To install Google Performance Tools
```bash
brew install google-perftools
brew install graphviz
```
Pyhton config
```
pip install geopandas
pip install https://github.com/jwass/geopandas_osm/zipball/master
```

To install Niels Lohmann's JSON Library

```bash
$ git clone https://github.com/nlohmann/json
$ cd json
$ cmake CMakeLists.txt
$ make
```


Source Code:
 * `graph_test.cpp` demonstrates how to construct 
    graphs and serialize their data in json objects, 
    and how to write the json object to a file.



# Compile

```bash
$ g++ graph_test.cpp -std=c++11 -o ./go \
    -I./ -I./lib/ -I./json/src -I../lib -I../shaffer 
```


pip install overpass
pip install overpy



To install Niels Lohmann's JSON Library

```bash
$ git clone https://github.com/nlohmann/json
$ cd json
$ cmake CMakeLists.txt
$ make
```

```bash
brew cask install gephi
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


## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

*IMPORTANT NOTE: ROTATION BY A CERTAIN ANGLE N TIMES WORKS PROPERLY (DOES NOT PRESENT ANY PROBLEMS WITH RECTANGLE'S COORDINATES UNWANTED CHANGE)*

Program zrobiony jest w ten sposob ze przy wielokrotnych obrotach wymiary pozostaja te same, a prostokat sie nie rozjezdza

``` Menu: 
o - obrot prostokata o zadany kat             /rectangle rotation
p - przesuniecie prostokata o zadany wektor   /rectangle translation
w - wyswietlenie wspolrzednych wierzcholkow   /print rectangle tops
m - wyswietl menu                             /show mennu
k - koniec dzialania programu                 /close program
```

## Tests
All tests which throw an ERROR are commented in code to work and all inconsistencies are written here.

IN TEST: V 5.02: Vector dzielenie wektorow przez maly skalar

#To run tests from test/main cpp run:
```
./unit_tests
```
On a Release type build
```
/home/krzysztof/PO/zad3-kgliwinski/prj/tests/main.cpp:200: ERROR: CHECK( res == b ) is NOT correct!
  values: CHECK( [ 40000000000.0000000000 ] [ 20000000000.0000000000 ] == [ 3999999999.9999995232 ] [ 1999999999.9999997616 ] 
  ```
  
  ##Test run:
  ```
  ===============================================================================
[doctest] test cases: 72 | 72 passed | 0 failed | 0 skipped
[doctest] assertions: 72 | 72 passed | 0 failed |
[doctest] Status: SUCCESS!
  ```




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

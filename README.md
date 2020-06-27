# How to build

```sh
conan install .. --build missing

cmake .. -GNinja \
-DCMAKE_CXX_COMPILER=/usr/local/bin/g++-9   \
-DCMAKE_C_COMPILER=/usr/local/bin/gcc-9
```

# Example

```
echo 'محمد' | ./bin/pointify-arabic

ݦݗݥڐ
```

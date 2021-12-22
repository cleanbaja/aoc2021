# Advent of Code 2021
My solutions for advent of code 2021 in C++17, I am doing this challenge to
get better at using c++ (more specifically the algorithms)

## Building
Meson build is used to build this project, and the inputs are stored in days/day<num>/input.txt
For example, to build and run day 3's solutions, run the following.

```
$ meson setup out
$ ninja -C out
$ ./out/days/day03/solution-03 days/day3/input.txt
```

*Copyright (c) 2021 cleanbaja, All Rights Reserved.*

#!/bin/bash

git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
make
sh m
./tester
cd ..

rm -rf ft_printf_tester
make fclean

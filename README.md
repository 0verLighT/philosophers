*This project has been created as part of the 42 curriculum by [amartel](https://profile.intra.42.fr/users/amartel)*

# Philosophers

thread ist tot

# Description

This project is a simulation of the dining philosophers problem, it using the `pthread` library to create threads and mutexes to synchronize them.
the program takes 4 arguments:
- `number_of_philosophers`: the number of philosophers
- `time_to_die`: if a philosopher doesn't start eating `time_to_die` milliseconds after starting their last meal or the beginning of the simulation, they die.
- `time_to_eat`: the time it takes for a philosopher to eat. During that time, they will need to hold the two forks on their left and right.
- `time_to_sleep`: the time a philosopher will spend sleeping.
- `eat_before_end` (optional argument): if all philosophers eat at least `eat_before_end` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

# Instructions

You can use `flake.nix` with `nix develop` (or direnv), it's require [Nix flakes](https://wiki.nixos.org/wiki/Flakes)

Makefile

```sh
cd philo
make -j8
./philo 5 500 200 100
```

meson.build

```sh
cd philo
meson setup build --prefix=$PWD --bindir=.
meson install -C build
./philo 5 500 200 100
```

# Resources

- [Developpez pthread (FRENCH)](https://franckh.developpez.com/tutoriels/posix/pthreads/)
- 42 student : some advises (how to create dead logic, parser with ft_atoi)
- gIA was used to correct the typo in the README.md, and to understand the routine in library pthread.

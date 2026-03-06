*This project has been created as part of the 42 curriculum by [amartel](https://profile.intra.42.fr/users/amartel)*

# Philosophers
thread ist tot

# Description

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

[Developpez pthread (FRENCH)](https://franckh.developpez.com/tutoriels/posix/pthreads/)

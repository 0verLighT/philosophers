{
  description = "flake (C/meson)";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
          nativeBuildInputs = with pkgs; [
            meson
            ninja
            pkg-config
            clang-tools
          ] ++ pkgs.lib.optionals pkgs.stdenv.isLinux [
            valgrind
            gdb
          ];

          shellHook = ''cc --version'';
        };
      }
    );
}

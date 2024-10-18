{ pkgs ? import <nixpkgs> {} }: pkgs.mkShell (with pkgs; {
  buildInputs = [
    cmake
    gdb
  ];
})

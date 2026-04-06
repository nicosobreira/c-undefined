{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  strictDeps = true;
  # Tools
  nativeBuildInputs = with pkgs; [
    git
    cmake
    gdb

    clang-tools
    cmake-language-server
  ];

  # Libraries
  # buildInputs = [
  # ];
}

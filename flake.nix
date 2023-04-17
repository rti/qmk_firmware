{
  description = "QMK dev shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-22.11";
  };

  outputs = { self, nixpkgs, ... }:
    let
      pkgs = (import nixpkgs) {
        system = "x86_64-linux";
      };

    in
    {
      devShells.x86_64-linux.default = pkgs.mkShell {
        packages = with pkgs; [
          qmk
          python3
          gcc-arm-embedded
          bear
        ];

        shellHook = ''
          echo
          ${pkgs.figlet}/bin/figlet "QMK dev shell"
          echo
          echo "Compile with:"
          echo "  $ bear -- qmk compile -kb splitkb/kyria -km rti -j16"
          echo "  $ bear -- qmk compile -kb beekeeb/piantor -km rti -j16"
          echo
        '';
      };
    };
}

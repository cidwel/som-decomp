; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA81
boss_lz_controls_daca81:
    ; backreference count 3, distance 968
    .byte $83, $C7
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

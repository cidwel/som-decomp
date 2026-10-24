; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B691
boss_lz_controls_dbb691:
    ; backreference count 3, distance 689
    .byte $82, $B0
    ; backreference count 10, distance 56
    .byte $9C, $37
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E4A9
boss_lz_controls_dae4a9:
    ; backreference count 3, distance 203
    .byte $80, $CA
    ; backreference count 9, distance 973
    .byte $B3, $CC
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

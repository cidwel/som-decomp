; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA1B
boss_lz_controls_daca1b:
    ; backreference count 9, distance 358
    .byte $B1, $65
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F331
boss_lz_controls_daf331:
    ; backreference count 6, distance 30
    .byte $B0, $1D
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

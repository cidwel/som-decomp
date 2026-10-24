; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB1D
boss_lz_controls_dabb1d:
    ; backreference count 3, distance 756
    .byte $82, $F3
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A

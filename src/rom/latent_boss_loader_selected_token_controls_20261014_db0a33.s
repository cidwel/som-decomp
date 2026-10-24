; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A33
boss_lz_controls_db0a33:
    ; backreference count 3, distance 2765
    .byte $8A, $CC
    ; backreference count 10, distance 21
    .byte $F0, $14
    ; backreference count 10, distance 22
    .byte $F0, $15
    ; backreference count 10, distance 19
    .byte $F0, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

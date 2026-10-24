; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $020F
boss_lz_controls_db020f:
    ; backreference count 5, distance 267
    .byte $A1, $0A
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A6F
boss_lz_controls_db0a6f:
    ; backreference count 4, distance 674
    .byte $92, $A1
    ; backreference count 10, distance 30
    .byte $F0, $1D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

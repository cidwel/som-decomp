; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0730
boss_lz_controls_db0730:
    ; backreference count 6, distance 67
    .byte $B0, $42
    ; backreference count 7, distance 1203
    .byte $C4, $B2
    ; backreference count 4, distance 168
    .byte $90, $A7
    ; backreference count 4, distance 6
    .byte $90, $05
    ; backreference count 5, distance 30
    .byte $A0, $1D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

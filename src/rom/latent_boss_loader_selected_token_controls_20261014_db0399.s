; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0399
boss_lz_controls_db0399:
    ; backreference count 6, distance 42
    .byte $B0, $29
    ; backreference count 5, distance 1017
    .byte $A3, $F8
    ; backreference count 4, distance 9
    .byte $90, $08
    ; backreference count 5, distance 43
    .byte $A0, $2A
    ; backreference count 3, distance 50
    .byte $80, $31
    ; backreference count 3, distance 1172
    .byte $84, $93
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B5C
boss_lz_controls_db0b5c:
    ; backreference count 10, distance 262
    .byte $F1, $05
    ; backreference count 10, distance 96
    .byte $F0, $5F
    ; backreference count 10, distance 96
    .byte $F0, $5F
    ; backreference count 10, distance 96
    .byte $F0, $5F
    ; backreference count 5, distance 96
    .byte $A0, $5F
    ; backreference count 4, distance 490
    .byte $91, $E9
    ; backreference count 10, distance 87
    .byte $F0, $56
    ; backreference count 10, distance 87
    .byte $F0, $56
    ; backreference count 10, distance 87
    .byte $F0, $56
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0ABC
boss_lz_controls_db0abc:
    ; backreference count 5, distance 1664
    .byte $A6, $7F
    ; backreference count 10, distance 81
    .byte $F0, $50
    ; backreference count 10, distance 81
    .byte $F0, $50
    ; backreference count 10, distance 81
    .byte $F0, $50
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; backreference count 10, distance 80
    .byte $F0, $4F
    ; backreference count 10, distance 80
    .byte $F0, $4F
    ; backreference count 10, distance 80
    .byte $F0, $4F
    ; backreference count 10, distance 80
    .byte $F0, $4F
    ; backreference count 7, distance 80
    .byte $C0, $4F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B23
boss_lz_controls_db0b23:
    ; backreference count 6, distance 42
    .byte $B0, $29
    ; backreference count 10, distance 186
    .byte $F0, $B9
    ; backreference count 10, distance 186
    .byte $F0, $B9
    ; backreference count 7, distance 14
    .byte $C0, $0D
    ; backreference count 5, distance 26
    .byte $A0, $19
    ; backreference count 10, distance 249
    .byte $F0, $F8
    ; backreference count 10, distance 166
    .byte $F0, $A5
    ; backreference count 7, distance 166
    .byte $C0, $A5
    ; backreference count 4, distance 93
    .byte $90, $5C
    ; backreference count 4, distance 173
    .byte $90, $AC
    ; backreference count 3, distance 93
    .byte $80, $5C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

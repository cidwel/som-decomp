; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09A2
boss_lz_controls_db09a2:
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; backreference count 4, distance 565
    .byte $92, $34
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; backreference count 4, distance 865
    .byte $93, $60
    ; backreference count 5, distance 156
    .byte $A0, $9B
    ; backreference count 4, distance 511
    .byte $91, $FE
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; backreference count 3, distance 10
    .byte $80, $09
    ; backreference count 5, distance 3465
    .byte $AD, $88
    ; backreference count 10, distance 9
    .byte $F0, $08
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

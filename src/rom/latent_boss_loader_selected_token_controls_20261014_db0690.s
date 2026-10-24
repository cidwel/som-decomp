; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0690
boss_lz_controls_db0690:
    ; backreference count 5, distance 1460
    .byte $A5, $B3
    ; backreference count 3, distance 45
    .byte $80, $2C
    ; backreference count 4, distance 9
    .byte $90, $08
    ; backreference count 3, distance 282
    .byte $81, $19
    ; backreference count 3, distance 204
    .byte $80, $CB
    ; backreference count 4, distance 9
    .byte $90, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

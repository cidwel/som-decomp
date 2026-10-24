; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0667
boss_lz_controls_db0667:
    ; backreference count 5, distance 2001
    .byte $A7, $D0
    ; backreference count 4, distance 8
    .byte $90, $07
    ; backreference count 4, distance 1310
    .byte $95, $1D
    ; backreference count 5, distance 1557
    .byte $A6, $14
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; backreference count 5, distance 2043
    .byte $A7, $FA
    ; backreference count 6, distance 2061
    .byte $B8, $0C
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

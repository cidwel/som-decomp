; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08E2
boss_lz_controls_db08e2:
    ; backreference count 5, distance 1568
    .byte $A6, $1F
    ; backreference count 6, distance 1478
    .byte $B5, $C5
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08C5
boss_lz_controls_db08c5:
    ; backreference count 6, distance 1742
    .byte $B6, $CD
    ; backreference count 4, distance 1390
    .byte $95, $6D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

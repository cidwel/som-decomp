; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D30A
boss_lz_controls_dbd30a:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF9C
boss_lz_controls_daef9c:
    ; backreference count 3, distance 698
    .byte $82, $B9
    ; backreference count 3, distance 1476
    .byte $85, $C3
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

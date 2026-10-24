; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA14
boss_lz_controls_daea14:
    ; backreference count 3, distance 77
    .byte $80, $4C
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

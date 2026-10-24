; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D08E
boss_lz_controls_dbd08e:
    ; backreference count 3, distance 1476
    .byte $85, $C3
    ; backreference count 3, distance 2154
    .byte $88, $69
    ; literal count 23; subsequent asset bytes excluded
    .byte $16

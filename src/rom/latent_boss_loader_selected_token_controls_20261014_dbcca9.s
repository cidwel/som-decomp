; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCA9
boss_lz_controls_dbcca9:
    ; backreference count 3, distance 1464
    .byte $85, $B7
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

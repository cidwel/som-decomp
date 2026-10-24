; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0ED
boss_lz_controls_dbd0ed:
    ; backreference count 3, distance 423
    .byte $81, $A6
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

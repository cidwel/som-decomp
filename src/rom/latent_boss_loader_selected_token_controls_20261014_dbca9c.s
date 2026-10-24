; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA9C
boss_lz_controls_dbca9c:
    ; backreference count 6, distance 22
    .byte $B0, $15
    ; backreference count 5, distance 219
    .byte $A0, $DA
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

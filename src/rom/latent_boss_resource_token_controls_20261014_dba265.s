; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A265
boss_lz_controls_dba265:
    ; backreference count 8, distance 1408
    .byte $AD, $7F
    ; literal count 20; subsequent asset bytes excluded
    .byte $13

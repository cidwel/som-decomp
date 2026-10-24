; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA74
boss_lz_controls_dbca74:
    ; backreference count 5, distance 56
    .byte $A0, $37
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

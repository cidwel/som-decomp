; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A34D
boss_lz_controls_dba34d:
    ; backreference count 4, distance 1091
    .byte $8C, $42
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

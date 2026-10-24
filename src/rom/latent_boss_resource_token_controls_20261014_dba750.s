; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A750
boss_lz_controls_dba750:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

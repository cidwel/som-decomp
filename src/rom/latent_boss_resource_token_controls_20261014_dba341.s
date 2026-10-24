; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A341
boss_lz_controls_dba341:
    ; backreference count 3, distance 82
    .byte $80, $51
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

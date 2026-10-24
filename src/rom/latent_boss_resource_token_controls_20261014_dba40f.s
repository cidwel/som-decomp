; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A40F
boss_lz_controls_dba40f:
    ; backreference count 3, distance 46
    .byte $80, $2D
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

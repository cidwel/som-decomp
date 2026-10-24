; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A65F
boss_lz_controls_dba65f:
    ; backreference count 3, distance 191
    .byte $80, $BE
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

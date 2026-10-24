; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A37F
boss_lz_controls_dba37f:
    ; backreference count 4, distance 49
    .byte $88, $30
    ; backreference count 4, distance 48
    .byte $88, $2F
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

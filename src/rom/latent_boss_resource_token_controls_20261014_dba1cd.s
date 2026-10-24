; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A1CD
boss_lz_controls_dba1cd:
    ; backreference count 4, distance 1770
    .byte $8E, $E9
    ; literal count 33; subsequent asset bytes excluded
    .byte $20

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A7AD
boss_lz_controls_dba7ad:
    ; backreference count 3, distance 182
    .byte $80, $B5
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F

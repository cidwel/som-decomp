; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A58B
boss_lz_controls_dba58b:
    ; backreference count 3, distance 99
    .byte $80, $62
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

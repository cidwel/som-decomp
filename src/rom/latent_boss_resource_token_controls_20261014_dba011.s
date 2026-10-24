; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A011
boss_lz_controls_dba011:
    ; backreference count 4, distance 1066
    .byte $8C, $29
    ; literal count 25; subsequent asset bytes excluded
    .byte $18

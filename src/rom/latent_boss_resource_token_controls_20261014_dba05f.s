; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A05F
boss_lz_controls_dba05f:
    ; backreference count 4, distance 1078
    .byte $8C, $35
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

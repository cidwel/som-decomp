; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A076
boss_lz_controls_dba076:
    ; backreference count 3, distance 1079
    .byte $84, $36
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

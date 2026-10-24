; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A099
boss_lz_controls_dba099:
    ; backreference count 7, distance 498
    .byte $A1, $F1
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

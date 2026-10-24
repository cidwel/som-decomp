; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A9A1
boss_lz_controls_dba9a1:
    ; backreference count 3, distance 498
    .byte $81, $F1
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D

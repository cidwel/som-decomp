; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F341
boss_lz_controls_daf341:
    ; backreference count 5, distance 1191
    .byte $A4, $A6
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

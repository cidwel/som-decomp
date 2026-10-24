; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F22F
boss_lz_controls_daf22f:
    ; backreference count 4, distance 167
    .byte $90, $A6
    ; literal count 80; subsequent asset bytes excluded
    .byte $4F

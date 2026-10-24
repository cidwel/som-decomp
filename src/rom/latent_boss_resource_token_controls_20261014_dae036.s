; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E036
boss_lz_controls_dae036:
    ; backreference count 8, distance 26
    .byte $A8, $19
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

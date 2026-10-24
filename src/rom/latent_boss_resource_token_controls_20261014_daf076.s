; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F076
boss_lz_controls_daf076:
    ; backreference count 6, distance 425
    .byte $B1, $A8
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

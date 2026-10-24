; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD5C
boss_lz_controls_dacd5c:
    ; backreference count 7, distance 461
    .byte $A1, $CC
    ; literal count 75; subsequent asset bytes excluded
    .byte $4A

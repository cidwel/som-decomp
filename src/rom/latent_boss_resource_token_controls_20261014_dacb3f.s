; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB3F
boss_lz_controls_dacb3f:
    ; backreference count 4, distance 1689
    .byte $8E, $98
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB4F
boss_lz_controls_dacb4f:
    ; backreference count 7, distance 1683
    .byte $A6, $92
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

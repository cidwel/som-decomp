; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C89F
boss_lz_controls_dac89f:
    ; backreference count 4, distance 560
    .byte $8A, $2F
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C60D
boss_lz_controls_dac60d:
    ; backreference count 3, distance 576
    .byte $82, $3F
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

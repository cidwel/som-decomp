; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C30F
boss_lz_controls_dac30f:
    ; backreference count 4, distance 74
    .byte $88, $49
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F

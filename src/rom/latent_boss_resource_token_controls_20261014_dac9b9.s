; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9B9
boss_lz_controls_dac9b9:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

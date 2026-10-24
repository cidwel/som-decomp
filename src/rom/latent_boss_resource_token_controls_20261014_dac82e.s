; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C82E
boss_lz_controls_dac82e:
    ; backreference count 4, distance 1126
    .byte $8C, $65
    ; backreference count 3, distance 491
    .byte $81, $EA
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

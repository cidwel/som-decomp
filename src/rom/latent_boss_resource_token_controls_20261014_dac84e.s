; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C84E
boss_lz_controls_dac84e:
    ; backreference count 3, distance 112
    .byte $80, $6F
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

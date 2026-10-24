; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C124
boss_lz_controls_dac124:
    ; backreference count 3, distance 85
    .byte $80, $54
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

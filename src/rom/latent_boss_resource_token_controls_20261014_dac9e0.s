; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9E0
boss_lz_controls_dac9e0:
    ; backreference count 5, distance 1180
    .byte $94, $9B
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

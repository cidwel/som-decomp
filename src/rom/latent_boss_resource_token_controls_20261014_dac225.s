; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C225
boss_lz_controls_dac225:
    ; backreference count 3, distance 982
    .byte $83, $D5
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

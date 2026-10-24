; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C78C
boss_lz_controls_dac78c:
    ; backreference count 18, distance 570
    .byte $FA, $39
    ; backreference count 5, distance 570
    .byte $92, $39
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1A7
boss_lz_controls_dbc1a7:
    ; backreference count 5, distance 1273
    .byte $94, $F8
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

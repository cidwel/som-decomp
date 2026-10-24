; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C187
boss_lz_controls_dbc187:
    ; backreference count 10, distance 1265
    .byte $BC, $F0
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

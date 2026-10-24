; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C16F
boss_lz_controls_dbc16f:
    ; backreference count 4, distance 70
    .byte $88, $45
    ; backreference count 5, distance 1208
    .byte $94, $B7
    ; backreference count 3, distance 144
    .byte $80, $8F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

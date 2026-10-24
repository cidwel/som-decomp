; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C26F
boss_lz_controls_dac26f:
    ; backreference count 3, distance 254
    .byte $80, $FD
    ; backreference count 4, distance 241
    .byte $84, $F0
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

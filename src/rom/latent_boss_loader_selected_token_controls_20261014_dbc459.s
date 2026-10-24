; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C459
boss_lz_controls_dbc459:
    ; backreference count 4, distance 16
    .byte $88, $0F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

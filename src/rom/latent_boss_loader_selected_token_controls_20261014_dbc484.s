; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C484
boss_lz_controls_dbc484:
    ; backreference count 3, distance 503
    .byte $81, $F6
    ; backreference count 4, distance 66
    .byte $88, $41
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E

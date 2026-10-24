; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4CA
boss_lz_controls_dbc4ca:
    ; backreference count 4, distance 19
    .byte $88, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4BF
boss_lz_controls_dbc4bf:
    ; backreference count 4, distance 11
    .byte $88, $0A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

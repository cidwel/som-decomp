; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B218
boss_lz_controls_dbb218:
    ; backreference count 9, distance 13
    .byte $98, $0C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2D9
boss_lz_controls_dbb2d9:
    ; backreference count 9, distance 13
    .byte $98, $0C
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

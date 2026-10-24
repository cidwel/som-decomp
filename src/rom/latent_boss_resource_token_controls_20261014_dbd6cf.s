; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6CF
boss_lz_controls_dbd6cf:
    ; backreference count 9, distance 1
    .byte $98, $00
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

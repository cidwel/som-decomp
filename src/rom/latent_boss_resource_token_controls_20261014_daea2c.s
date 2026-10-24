; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA2C
boss_lz_controls_daea2c:
    ; backreference count 6, distance 198
    .byte $B0, $C5
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

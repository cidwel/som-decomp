; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE2C
boss_lz_controls_dbbe2c:
    ; backreference count 4, distance 182
    .byte $88, $B5
    ; literal count 18; subsequent asset bytes excluded
    .byte $11

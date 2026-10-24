; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCA5
boss_lz_controls_dbcca5:
    ; backreference count 6, distance 1464
    .byte $B5, $B7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

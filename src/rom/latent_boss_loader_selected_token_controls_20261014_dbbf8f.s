; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF8F
boss_lz_controls_dbbf8f:
    ; backreference count 6, distance 544
    .byte $9A, $1F
    ; literal count 63; subsequent asset bytes excluded
    .byte $3E

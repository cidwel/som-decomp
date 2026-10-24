; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B1D4
boss_lz_controls_dbb1d4:
    ; backreference count 4, distance 541
    .byte $86, $1C
    ; literal count 38; subsequent asset bytes excluded
    .byte $25

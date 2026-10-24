; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B480
boss_lz_controls_dbb480:
    ; backreference count 3, distance 26
    .byte $80, $19
    ; literal count 22; subsequent asset bytes excluded
    .byte $15

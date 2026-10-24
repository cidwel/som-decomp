; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA04
boss_lz_controls_dada04:
    ; backreference count 4, distance 39
    .byte $88, $26
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

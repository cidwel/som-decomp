; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA75
boss_lz_controls_dada75:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

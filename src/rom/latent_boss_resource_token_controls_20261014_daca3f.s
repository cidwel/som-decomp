; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA3F
boss_lz_controls_daca3f:
    ; backreference count 3, distance 1772
    .byte $86, $EB
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

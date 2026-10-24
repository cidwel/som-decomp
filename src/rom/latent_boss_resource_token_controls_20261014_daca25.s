; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA25
boss_lz_controls_daca25:
    ; backreference count 3, distance 78
    .byte $80, $4D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA8D
boss_lz_controls_dbca8d:
    ; backreference count 3, distance 43
    .byte $80, $2A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

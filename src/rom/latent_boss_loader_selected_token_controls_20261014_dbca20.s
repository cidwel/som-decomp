; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA20
boss_lz_controls_dbca20:
    ; backreference count 3, distance 743
    .byte $82, $E6
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

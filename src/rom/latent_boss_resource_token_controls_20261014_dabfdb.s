; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFDB
boss_lz_controls_dabfdb:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

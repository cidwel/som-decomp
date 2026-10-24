; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9950
boss_lz_controls_db9950:
    ; backreference count 4, distance 2810
    .byte $9A, $F9
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

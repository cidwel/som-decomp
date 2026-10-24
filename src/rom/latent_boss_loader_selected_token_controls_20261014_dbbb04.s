; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB04
boss_lz_controls_dbbb04:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; backreference count 7, distance 498
    .byte $91, $F1
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

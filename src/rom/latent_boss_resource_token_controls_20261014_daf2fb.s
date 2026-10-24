; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2FB
boss_lz_controls_daf2fb:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

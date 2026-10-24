; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9A4C
boss_lz_controls_db9a4c:
    ; backreference count 3, distance 2253
    .byte $88, $CC
    ; backreference count 3, distance 556
    .byte $82, $2B
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

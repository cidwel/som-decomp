; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09D5
boss_lz_controls_db09d5:
    ; backreference count 6, distance 7
    .byte $B0, $06
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

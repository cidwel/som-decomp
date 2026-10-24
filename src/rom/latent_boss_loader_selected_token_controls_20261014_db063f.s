; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $063F
boss_lz_controls_db063f:
    ; backreference count 6, distance 1412
    .byte $B5, $83
    ; backreference count 5, distance 790
    .byte $A3, $15
    ; backreference count 3, distance 1145
    .byte $84, $78
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

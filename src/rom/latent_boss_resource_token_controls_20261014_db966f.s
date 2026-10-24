; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $966F
boss_lz_controls_db966f:
    ; backreference count 4, distance 444
    .byte $91, $BB
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

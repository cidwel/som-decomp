; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B786
boss_lz_controls_dab786:
    ; backreference count 3, distance 377
    .byte $81, $78
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

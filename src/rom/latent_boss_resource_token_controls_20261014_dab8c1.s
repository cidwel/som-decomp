; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8C1
boss_lz_controls_dab8c1:
    ; backreference count 3, distance 444
    .byte $81, $BB
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

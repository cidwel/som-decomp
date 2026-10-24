; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D1FB
boss_lz_controls_dad1fb:
    ; backreference count 4, distance 637
    .byte $8A, $7C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

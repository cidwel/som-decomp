; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D65C
boss_lz_controls_dad65c:
    ; backreference count 3, distance 1666
    .byte $86, $81
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

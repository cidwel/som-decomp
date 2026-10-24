; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAB5
boss_lz_controls_dabab5:
    ; backreference count 9, distance 49
    .byte $98, $30
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

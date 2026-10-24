; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07A1
boss_lz_controls_db07a1:
    ; backreference count 6, distance 597
    .byte $B2, $54
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

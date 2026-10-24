; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B622
boss_lz_controls_dbb622:
    ; backreference count 3, distance 290
    .byte $81, $21
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

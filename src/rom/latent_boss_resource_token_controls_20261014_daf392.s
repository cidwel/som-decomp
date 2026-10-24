; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F392
boss_lz_controls_daf392:
    ; backreference count 4, distance 1088
    .byte $94, $3F
    ; backreference count 3, distance 3251
    .byte $8C, $B2
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3AB
boss_lz_controls_daf3ab:
    ; backreference count 9, distance 3251
    .byte $EC, $B2
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

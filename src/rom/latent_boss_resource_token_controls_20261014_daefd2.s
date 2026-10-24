; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFD2
boss_lz_controls_daefd2:
    ; backreference count 4, distance 261
    .byte $91, $04
    ; literal count 25; subsequent asset bytes excluded
    .byte $18

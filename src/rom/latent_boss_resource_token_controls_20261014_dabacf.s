; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BACF
boss_lz_controls_dabacf:
    ; backreference count 7, distance 263
    .byte $91, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

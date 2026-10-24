; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C99F
boss_lz_controls_dac99f:
    ; backreference count 3, distance 604
    .byte $82, $5B
    ; backreference count 15, distance 1170
    .byte $E4, $91
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

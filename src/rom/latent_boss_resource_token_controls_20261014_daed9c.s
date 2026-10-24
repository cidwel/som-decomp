; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED9C
boss_lz_controls_daed9c:
    ; backreference count 10, distance 400
    .byte $F1, $8F
    ; backreference count 6, distance 114
    .byte $B0, $71
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

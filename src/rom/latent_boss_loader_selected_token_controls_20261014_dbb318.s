; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B318
boss_lz_controls_dbb318:
    ; backreference count 3, distance 505
    .byte $81, $F8
    ; backreference count 24, distance 1
    .byte $D4, $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A52
boss_lz_controls_db0a52:
    ; backreference count 4, distance 395
    .byte $91, $8A
    ; backreference count 4, distance 2510
    .byte $99, $CD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

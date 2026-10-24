; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $92F3
boss_lz_controls_db92f3:
    ; backreference count 10, distance 119
    .byte $F0, $76
    ; backreference count 4, distance 1
    .byte $90, $00
    ; literal count 22; subsequent asset bytes excluded
    .byte $15

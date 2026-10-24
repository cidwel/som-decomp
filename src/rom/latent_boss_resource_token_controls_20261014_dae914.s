; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E914
boss_lz_controls_dae914:
    ; backreference count 6, distance 58
    .byte $B0, $39
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 4, distance 1
    .byte $90, $00
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

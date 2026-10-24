; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0301
boss_lz_controls_db0301:
    ; backreference count 8, distance 196
    .byte $D0, $C3
    ; backreference count 3, distance 523
    .byte $82, $0A
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

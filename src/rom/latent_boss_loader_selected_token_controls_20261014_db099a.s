; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $099A
boss_lz_controls_db099a:
    ; backreference count 7, distance 3411
    .byte $CD, $52
    ; backreference count 4, distance 283
    .byte $91, $1A
    ; backreference count 7, distance 9
    .byte $C0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

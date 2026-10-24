; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $055D
boss_lz_controls_db055d:
    ; backreference count 4, distance 1275
    .byte $94, $FA
    ; backreference count 3, distance 265
    .byte $81, $08
    ; backreference count 4, distance 1425
    .byte $95, $90
    ; backreference count 3, distance 134
    .byte $80, $85
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

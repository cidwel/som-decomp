; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $089A
boss_lz_controls_db089a:
    ; backreference count 6, distance 1383
    .byte $B5, $66
    ; backreference count 4, distance 258
    .byte $91, $01
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $096A
boss_lz_controls_db096a:
    ; backreference count 6, distance 3197
    .byte $BC, $7C
    ; backreference count 3, distance 1089
    .byte $84, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07C4
boss_lz_controls_db07c4:
    ; backreference count 5, distance 1426
    .byte $A5, $91
    ; backreference count 3, distance 544
    .byte $82, $1F
    ; backreference count 6, distance 1427
    .byte $B5, $92
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

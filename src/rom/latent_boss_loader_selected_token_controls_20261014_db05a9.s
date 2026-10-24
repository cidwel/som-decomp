; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05A9
boss_lz_controls_db05a9:
    ; backreference count 5, distance 432
    .byte $A1, $AF
    ; backreference count 3, distance 165
    .byte $80, $A4
    ; backreference count 4, distance 1286
    .byte $95, $05
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; backreference count 6, distance 1395
    .byte $B5, $72
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

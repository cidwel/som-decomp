; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06F3
boss_lz_controls_db06f3:
    ; backreference count 4, distance 434
    .byte $91, $B1
    ; backreference count 5, distance 1104
    .byte $A4, $4F
    ; backreference count 6, distance 1314
    .byte $B5, $21
    ; backreference count 3, distance 1107
    .byte $84, $52
    ; backreference count 5, distance 662
    .byte $A2, $95
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

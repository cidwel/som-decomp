; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05E0
boss_lz_controls_db05e0:
    ; backreference count 5, distance 614
    .byte $A2, $65
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; backreference count 7, distance 10
    .byte $C0, $09
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

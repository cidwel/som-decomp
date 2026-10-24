; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09F6
boss_lz_controls_db09f6:
    ; backreference count 5, distance 2290
    .byte $A8, $F1
    ; backreference count 3, distance 1355
    .byte $85, $4A
    ; backreference count 5, distance 6
    .byte $A0, $05
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

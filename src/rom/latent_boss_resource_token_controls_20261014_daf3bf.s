; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3BF
boss_lz_controls_daf3bf:
    ; backreference count 10, distance 167
    .byte $F0, $A6
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 5, distance 1
    .byte $A0, $00

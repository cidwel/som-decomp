; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC96
boss_lz_controls_dabc96:
    ; backreference count 12, distance 80
    .byte $A4, $4F
    ; backreference count 5, distance 41
    .byte $88, $28
    ; backreference count 16, distance 1
    .byte $B4, $00

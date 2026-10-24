; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AD9B
boss_lz_controls_dbad9b:
    ; backreference count 3, distance 219
    .byte $80, $DA
    ; backreference count 34, distance 1
    .byte $FC, $00
    ; backreference count 9, distance 1
    .byte $98, $00

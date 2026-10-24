; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0661
boss_lz_controls_db0661:
    ; backreference count 5, distance 1550
    .byte $A6, $0D
    ; backreference count 4, distance 165
    .byte $90, $A4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

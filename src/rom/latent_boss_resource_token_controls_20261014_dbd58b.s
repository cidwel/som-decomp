; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D58B
boss_lz_controls_dbd58b:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; backreference count 4, distance 462
    .byte $85, $CD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

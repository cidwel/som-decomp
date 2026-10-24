; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3A1
boss_lz_controls_dba3a1:
    ; backreference count 4, distance 28
    .byte $88, $1B
    ; backreference count 18, distance 1
    .byte $F8, $00
    ; backreference count 7, distance 356
    .byte $A1, $63
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

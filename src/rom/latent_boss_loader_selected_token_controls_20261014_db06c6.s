; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06C6
boss_lz_controls_db06c6:
    ; backreference count 4, distance 2211
    .byte $98, $A2
    ; backreference count 3, distance 134
    .byte $80, $85
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

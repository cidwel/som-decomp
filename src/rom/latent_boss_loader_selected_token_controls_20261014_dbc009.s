; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C009
boss_lz_controls_dbc009:
    ; backreference count 4, distance 902
    .byte $8B, $85
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

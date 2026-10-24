; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2AC
boss_lz_controls_dbc2ac:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

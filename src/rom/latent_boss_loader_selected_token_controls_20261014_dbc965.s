; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C965
boss_lz_controls_dbc965:
    ; backreference count 3, distance 384
    .byte $81, $7F
    ; backreference count 4, distance 338
    .byte $91, $51
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

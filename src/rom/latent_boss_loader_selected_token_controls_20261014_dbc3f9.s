; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3F9
boss_lz_controls_dbc3f9:
    ; backreference count 3, distance 22
    .byte $80, $15
    ; backreference count 3, distance 1228
    .byte $84, $CB
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

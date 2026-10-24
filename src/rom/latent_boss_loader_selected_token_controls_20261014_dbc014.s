; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C014
boss_lz_controls_dbc014:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C09C
boss_lz_controls_dbc09c:
    ; backreference count 7, distance 165
    .byte $A0, $A4
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

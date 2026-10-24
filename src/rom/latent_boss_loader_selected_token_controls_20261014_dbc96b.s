; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C96B
boss_lz_controls_dbc96b:
    ; backreference count 5, distance 6
    .byte $A0, $05
    ; literal count 25; subsequent asset bytes excluded
    .byte $18

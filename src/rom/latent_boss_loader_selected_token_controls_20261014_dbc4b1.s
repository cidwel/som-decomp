; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4B1
boss_lz_controls_dbc4b1:
    ; backreference count 8, distance 132
    .byte $A8, $83
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

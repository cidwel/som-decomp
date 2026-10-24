; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C30B
boss_lz_controls_dbc30b:
    ; backreference count 4, distance 1728
    .byte $8E, $BF
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

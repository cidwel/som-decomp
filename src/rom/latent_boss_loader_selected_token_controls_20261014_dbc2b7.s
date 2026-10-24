; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2B7
boss_lz_controls_dbc2b7:
    ; backreference count 4, distance 1506
    .byte $8D, $E1
    ; literal count 64; subsequent asset bytes excluded
    .byte $3F

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0EB
boss_lz_controls_dbc0eb:
    ; backreference count 9, distance 1092
    .byte $B4, $43
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A

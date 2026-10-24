; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4CE
boss_lz_controls_dbc4ce:
    ; backreference count 3, distance 1307
    .byte $85, $1A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

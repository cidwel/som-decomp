; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C629
boss_lz_controls_dbc629:
    ; backreference count 12, distance 42
    .byte $C8, $29
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D

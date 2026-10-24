; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4C3
boss_lz_controls_dbc4c3:
    ; backreference count 10, distance 890
    .byte $BB, $79
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0A8
boss_lz_controls_dbc0a8:
    ; backreference count 3, distance 70
    .byte $80, $45
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F

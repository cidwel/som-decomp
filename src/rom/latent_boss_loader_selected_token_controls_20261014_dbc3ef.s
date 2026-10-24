; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3EF
boss_lz_controls_dbc3ef:
    ; backreference count 3, distance 81
    .byte $80, $50
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

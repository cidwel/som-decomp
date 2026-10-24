; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C480
boss_lz_controls_dbc480:
    ; backreference count 3, distance 64
    .byte $80, $3F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

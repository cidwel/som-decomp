; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C77B
boss_lz_controls_dbc77b:
    ; backreference count 3, distance 92
    .byte $80, $5B
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C85D
boss_lz_controls_dbc85d:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 124; subsequent asset bytes excluded
    .byte $7B

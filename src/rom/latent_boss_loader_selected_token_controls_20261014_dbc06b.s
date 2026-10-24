; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C06B
boss_lz_controls_dbc06b:
    ; backreference count 3, distance 63
    .byte $80, $3E
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

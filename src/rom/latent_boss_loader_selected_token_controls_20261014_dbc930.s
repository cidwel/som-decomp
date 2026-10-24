; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C930
boss_lz_controls_dbc930:
    ; backreference count 3, distance 22
    .byte $80, $15
    ; literal count 50; subsequent asset bytes excluded
    .byte $31

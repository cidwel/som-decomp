; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C2B0
boss_lz_controls_dbc2b0:
    ; backreference count 3, distance 352
    .byte $81, $5F
    ; backreference count 5, distance 282
    .byte $91, $19
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

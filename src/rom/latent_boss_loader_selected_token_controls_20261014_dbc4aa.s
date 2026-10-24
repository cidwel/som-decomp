; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4AA
boss_lz_controls_dbc4aa:
    ; backreference count 3, distance 1276
    .byte $84, $FB
    ; backreference count 4, distance 859
    .byte $8B, $5A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

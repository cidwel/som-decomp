; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C3BE
boss_lz_controls_dbc3be:
    ; backreference count 6, distance 1004
    .byte $9B, $EB
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

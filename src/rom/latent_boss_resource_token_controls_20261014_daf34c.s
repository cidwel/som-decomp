; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F34C
boss_lz_controls_daf34c:
    ; backreference count 6, distance 93
    .byte $B0, $5C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

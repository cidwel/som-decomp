; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B122
boss_lz_controls_dbb122:
    ; backreference count 3, distance 262
    .byte $81, $05
    ; literal count 37; subsequent asset bytes excluded
    .byte $24

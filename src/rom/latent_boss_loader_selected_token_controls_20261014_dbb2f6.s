; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2F6
boss_lz_controls_dbb2f6:
    ; backreference count 6, distance 15
    .byte $8C, $0E
    ; literal count 18; subsequent asset bytes excluded
    .byte $11

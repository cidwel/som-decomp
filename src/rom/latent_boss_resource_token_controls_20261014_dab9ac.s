; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9AC
boss_lz_controls_dab9ac:
    ; backreference count 6, distance 74
    .byte $8C, $49
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

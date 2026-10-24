; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B654
boss_lz_controls_dab654:
    ; backreference count 7, distance 16
    .byte $90, $0F
    ; literal count 46; subsequent asset bytes excluded
    .byte $2D

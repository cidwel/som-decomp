; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8AD
boss_lz_controls_dab8ad:
    ; backreference count 17, distance 16
    .byte $B8, $0F
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

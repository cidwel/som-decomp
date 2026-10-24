; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B642
boss_lz_controls_dbb642:
    ; backreference count 8, distance 16
    .byte $94, $0F
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E

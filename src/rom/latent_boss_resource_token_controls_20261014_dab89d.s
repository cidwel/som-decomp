; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B89D
boss_lz_controls_dab89d:
    ; backreference count 3, distance 58
    .byte $80, $39
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

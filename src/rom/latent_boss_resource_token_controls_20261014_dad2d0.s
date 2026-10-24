; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2D0
boss_lz_controls_dad2d0:
    ; backreference count 3, distance 30
    .byte $80, $1D
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

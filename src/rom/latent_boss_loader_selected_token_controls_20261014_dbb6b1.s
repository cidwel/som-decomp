; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6B1
boss_lz_controls_dbb6b1:
    ; backreference count 3, distance 866
    .byte $83, $61
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

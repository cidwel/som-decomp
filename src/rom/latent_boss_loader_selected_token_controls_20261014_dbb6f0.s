; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6F0
boss_lz_controls_dbb6f0:
    ; backreference count 5, distance 528
    .byte $8A, $0F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

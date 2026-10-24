; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6D5
boss_lz_controls_dbb6d5:
    ; backreference count 4, distance 445
    .byte $85, $BC
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6A2
boss_lz_controls_dbb6a2:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6BD
boss_lz_controls_dbb6bd:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

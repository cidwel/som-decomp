; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6DA
boss_lz_controls_dbb6da:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 19; subsequent asset bytes excluded
    .byte $12

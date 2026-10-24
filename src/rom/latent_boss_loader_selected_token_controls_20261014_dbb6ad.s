; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6AD
boss_lz_controls_dbb6ad:
    ; backreference count 3, distance 255
    .byte $80, $FE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

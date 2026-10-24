; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B822
boss_lz_controls_dbb822:
    ; backreference count 4, distance 455
    .byte $85, $C6
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

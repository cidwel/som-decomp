; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D38F
boss_lz_controls_dbd38f:
    ; backreference count 4, distance 8
    .byte $84, $07
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

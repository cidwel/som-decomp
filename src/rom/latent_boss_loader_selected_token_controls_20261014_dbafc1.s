; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AFC1
boss_lz_controls_dbafc1:
    ; backreference count 14, distance 435
    .byte $AD, $B2
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

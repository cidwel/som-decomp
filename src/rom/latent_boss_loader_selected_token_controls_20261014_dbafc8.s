; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AFC8
boss_lz_controls_dbafc8:
    ; backreference count 7, distance 435
    .byte $91, $B2
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

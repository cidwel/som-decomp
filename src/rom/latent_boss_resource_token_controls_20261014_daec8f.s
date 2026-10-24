; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC8F
boss_lz_controls_daec8f:
    ; backreference count 3, distance 1208
    .byte $84, $B7
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

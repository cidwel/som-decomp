; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B948
boss_lz_controls_dab948:
    ; backreference count 6, distance 440
    .byte $8D, $B7
    ; backreference count 23, distance 495
    .byte $D1, $EE
    ; literal count 24; subsequent asset bytes excluded
    .byte $17

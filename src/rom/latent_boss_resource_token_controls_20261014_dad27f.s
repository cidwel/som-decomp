; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D27F
boss_lz_controls_dad27f:
    ; backreference count 4, distance 334
    .byte $89, $4D
    ; backreference count 3, distance 899
    .byte $83, $82
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B10F
boss_lz_controls_dbb10f:
    ; backreference count 4, distance 367
    .byte $85, $6E
    ; backreference count 3, distance 803
    .byte $83, $22
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B687
boss_lz_controls_dbb687:
    ; backreference count 5, distance 57
    .byte $88, $38
    ; backreference count 10, distance 56
    .byte $9C, $37
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

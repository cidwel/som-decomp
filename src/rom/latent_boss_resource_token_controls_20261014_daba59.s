; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA59
boss_lz_controls_daba59:
    ; backreference count 3, distance 390
    .byte $81, $85
    ; backreference count 4, distance 506
    .byte $85, $F9
    ; backreference count 5, distance 110
    .byte $88, $6D
    ; backreference count 7, distance 12
    .byte $90, $0B
    ; backreference count 6, distance 114
    .byte $8C, $71
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

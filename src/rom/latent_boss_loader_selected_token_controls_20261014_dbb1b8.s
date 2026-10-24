; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B1B8
boss_lz_controls_dbb1b8:
    ; backreference count 6, distance 13
    .byte $8C, $0C
    ; backreference count 3, distance 289
    .byte $81, $20
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F118
boss_lz_controls_daf118:
    ; backreference count 3, distance 452
    .byte $81, $C3
    ; backreference count 7, distance 857
    .byte $C3, $58
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F

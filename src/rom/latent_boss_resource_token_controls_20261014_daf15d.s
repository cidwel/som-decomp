; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F15D
boss_lz_controls_daf15d:
    ; backreference count 3, distance 468
    .byte $81, $D3
    ; backreference count 3, distance 18
    .byte $80, $11
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E

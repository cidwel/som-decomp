; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB7F
boss_lz_controls_dabb7f:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B741
boss_lz_controls_dab741:
    ; backreference count 3, distance 283
    .byte $81, $1A
    ; backreference count 11, distance 14
    .byte $A0, $0D
    ; literal count 64; subsequent asset bytes excluded
    .byte $3F

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2F0
boss_lz_controls_dbb2f0:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; backreference count 4, distance 15
    .byte $84, $0E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

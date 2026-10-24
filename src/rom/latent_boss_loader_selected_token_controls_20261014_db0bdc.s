; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BDC
boss_lz_controls_db0bdc:
    ; backreference count 4, distance 88
    .byte $90, $57
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; backreference count 6, distance 25
    .byte $B0, $18
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

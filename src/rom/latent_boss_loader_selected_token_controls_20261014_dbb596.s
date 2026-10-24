; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B596
boss_lz_controls_dbb596:
    ; backreference count 3, distance 436
    .byte $81, $B3
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

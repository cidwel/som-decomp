; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAC2
boss_lz_controls_dabac2:
    ; backreference count 6, distance 267
    .byte $8D, $0A
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0265
boss_lz_controls_db0265:
    ; backreference count 4, distance 203
    .byte $90, $CA
    ; backreference count 3, distance 611
    .byte $82, $62
    ; backreference count 3, distance 416
    .byte $81, $9F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

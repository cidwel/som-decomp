; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2C5
boss_lz_controls_daf2c5:
    ; backreference count 3, distance 448
    .byte $81, $BF
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

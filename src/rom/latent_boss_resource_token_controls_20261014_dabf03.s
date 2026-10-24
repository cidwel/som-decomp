; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF03
boss_lz_controls_dabf03:
    ; backreference count 3, distance 269
    .byte $81, $0C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

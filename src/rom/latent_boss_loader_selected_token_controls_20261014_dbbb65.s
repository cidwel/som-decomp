; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB65
boss_lz_controls_dbbb65:
    ; backreference count 3, distance 2
    .byte $80, $01
    ; backreference count 23, distance 1
    .byte $D0, $00
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

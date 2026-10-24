; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9995
boss_lz_controls_db9995:
    ; backreference count 4, distance 13
    .byte $90, $0C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

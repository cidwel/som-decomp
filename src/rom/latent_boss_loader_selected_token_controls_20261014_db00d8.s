; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00D8
boss_lz_controls_db00d8:
    ; backreference count 4, distance 7
    .byte $90, $06
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

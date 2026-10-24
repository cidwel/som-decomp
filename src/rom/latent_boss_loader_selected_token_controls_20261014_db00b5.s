; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00B5
boss_lz_controls_db00b5:
    ; backreference count 4, distance 6
    .byte $90, $05
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

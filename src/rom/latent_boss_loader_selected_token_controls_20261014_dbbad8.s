; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAD8
boss_lz_controls_dbbad8:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

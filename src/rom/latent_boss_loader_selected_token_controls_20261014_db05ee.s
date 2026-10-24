; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05EE
boss_lz_controls_db05ee:
    ; backreference count 4, distance 391
    .byte $91, $86
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

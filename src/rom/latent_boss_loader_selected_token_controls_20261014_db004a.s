; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $004A
boss_lz_controls_db004a:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 4; subsequent asset bytes excluded
    .byte $03

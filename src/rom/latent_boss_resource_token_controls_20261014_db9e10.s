; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9E10
boss_lz_controls_db9e10:
    ; backreference count 3, distance 29
    .byte $80, $1C
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

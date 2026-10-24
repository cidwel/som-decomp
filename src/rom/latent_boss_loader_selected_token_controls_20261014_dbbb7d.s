; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB7D
boss_lz_controls_dbbb7d:
    ; backreference count 3, distance 4
    .byte $80, $03
    ; literal count 19; subsequent asset bytes excluded
    .byte $12

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9E01
boss_lz_controls_db9e01:
    ; backreference count 3, distance 336
    .byte $81, $4F
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

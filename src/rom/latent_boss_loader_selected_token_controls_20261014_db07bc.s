; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07BC
boss_lz_controls_db07bc:
    ; backreference count 4, distance 384
    .byte $91, $7F
    ; backreference count 4, distance 397
    .byte $91, $8C
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

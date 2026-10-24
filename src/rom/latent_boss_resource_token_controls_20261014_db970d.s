; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $970D
boss_lz_controls_db970d:
    ; backreference count 4, distance 223
    .byte $90, $DE
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9C19
boss_lz_controls_db9c19:
    ; backreference count 10, distance 185
    .byte $B8, $B8
    ; literal count 56; subsequent asset bytes excluded
    .byte $37

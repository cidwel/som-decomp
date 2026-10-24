; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $045F
boss_lz_controls_db045f:
    ; backreference count 4, distance 320
    .byte $91, $3F
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

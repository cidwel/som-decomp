; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $060D
boss_lz_controls_db060d:
    ; backreference count 4, distance 466
    .byte $91, $D1
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

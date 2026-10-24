; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F31C
boss_lz_controls_daf31c:
    ; backreference count 4, distance 2413
    .byte $99, $6C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

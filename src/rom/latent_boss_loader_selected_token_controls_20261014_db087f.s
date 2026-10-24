; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $087F
boss_lz_controls_db087f:
    ; backreference count 6, distance 248
    .byte $B0, $F7
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

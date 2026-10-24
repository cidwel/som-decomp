; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6BC
boss_lz_controls_dab6bc:
    ; backreference count 24, distance 1
    .byte $D4, $00
    ; literal count 101; subsequent asset bytes excluded
    .byte $64

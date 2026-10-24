; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF6F
boss_lz_controls_dadf6f:
    ; backreference count 5, distance 219
    .byte $90, $DA
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

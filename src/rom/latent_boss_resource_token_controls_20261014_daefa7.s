; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFA7
boss_lz_controls_daefa7:
    ; backreference count 4, distance 700
    .byte $92, $BB
    ; literal count 40; subsequent asset bytes excluded
    .byte $27

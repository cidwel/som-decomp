; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFAF
boss_lz_controls_dadfaf:
    ; backreference count 4, distance 453
    .byte $89, $C4
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

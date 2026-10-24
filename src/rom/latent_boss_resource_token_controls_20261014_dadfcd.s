; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFCD
boss_lz_controls_dadfcd:
    ; backreference count 3, distance 1190
    .byte $84, $A5
    ; literal count 22; subsequent asset bytes excluded
    .byte $15

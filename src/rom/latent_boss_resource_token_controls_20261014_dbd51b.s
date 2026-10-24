; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D51B
boss_lz_controls_dbd51b:
    ; backreference count 12, distance 114
    .byte $A4, $71
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

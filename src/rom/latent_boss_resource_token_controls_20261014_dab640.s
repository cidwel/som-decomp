; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B640
boss_lz_controls_dab640:
    ; backreference count 3, distance 1
    .byte $80, $00
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

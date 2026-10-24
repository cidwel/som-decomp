; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B27B
boss_lz_controls_dbb27b:
    ; backreference count 4, distance 56
    .byte $84, $37
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

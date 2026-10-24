; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B3F1
boss_lz_controls_dbb3f1:
    ; backreference count 3, distance 25
    .byte $80, $18
    ; backreference count 15, distance 1
    .byte $B0, $00
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F

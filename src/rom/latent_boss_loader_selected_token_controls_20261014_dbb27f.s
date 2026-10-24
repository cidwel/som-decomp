; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B27F
boss_lz_controls_dbb27f:
    ; backreference count 3, distance 49
    .byte $80, $30
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

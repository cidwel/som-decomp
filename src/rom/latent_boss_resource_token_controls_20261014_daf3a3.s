; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3A3
boss_lz_controls_daf3a3:
    ; backreference count 6, distance 3251
    .byte $BC, $B2
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

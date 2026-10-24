; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05DA
boss_lz_controls_db05da:
    ; backreference count 6, distance 464
    .byte $B1, $CF
    ; backreference count 9, distance 488
    .byte $E1, $E7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B670
boss_lz_controls_dbb670:
    ; backreference count 9, distance 57
    .byte $98, $38
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

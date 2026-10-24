; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7FD
boss_lz_controls_dbb7fd:
    ; backreference count 3, distance 390
    .byte $81, $85
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

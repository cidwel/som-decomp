; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCDC
boss_lz_controls_dbbcdc:
    ; backreference count 3, distance 23
    .byte $80, $16
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E325
boss_lz_controls_dae325:
    ; backreference count 9, distance 997
    .byte $B3, $E4
    ; backreference count 3, distance 240
    .byte $80, $EF
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

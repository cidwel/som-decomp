; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E3B0
boss_lz_controls_dae3b0:
    ; backreference count 9, distance 703
    .byte $B2, $BE
    ; backreference count 3, distance 33
    .byte $80, $20
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

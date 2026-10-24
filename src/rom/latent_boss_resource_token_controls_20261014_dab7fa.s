; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7FA
boss_lz_controls_dab7fa:
    ; backreference count 4, distance 481
    .byte $85, $E0
    ; literal count 23; subsequent asset bytes excluded
    .byte $16

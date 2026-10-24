; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E52B
boss_lz_controls_dae52b:
    ; backreference count 10, distance 954
    .byte $BB, $B9
    ; literal count 52; subsequent asset bytes excluded
    .byte $33

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E97F
boss_lz_controls_dae97f:
    ; backreference count 3, distance 446
    .byte $81, $BD
    ; backreference count 3, distance 990
    .byte $83, $DD
    ; backreference count 3, distance 82
    .byte $80, $51
    ; literal count 18; subsequent asset bytes excluded
    .byte $11

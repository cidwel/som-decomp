; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E03F
boss_lz_controls_dae03f:
    ; backreference count 3, distance 151
    .byte $80, $96
    ; literal count 42; subsequent asset bytes excluded
    .byte $29

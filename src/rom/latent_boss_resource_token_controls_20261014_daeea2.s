; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EEA2
boss_lz_controls_daeea2:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

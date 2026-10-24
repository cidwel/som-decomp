; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C1CF
boss_lz_controls_dac1cf:
    ; backreference count 3, distance 57
    .byte $80, $38
    ; backreference count 3, distance 308
    .byte $81, $33
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

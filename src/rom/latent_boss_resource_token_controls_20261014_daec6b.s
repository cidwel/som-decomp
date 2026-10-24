; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC6B
boss_lz_controls_daec6b:
    ; backreference count 3, distance 23
    .byte $80, $16
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

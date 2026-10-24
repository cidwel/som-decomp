; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EE38
boss_lz_controls_daee38:
    ; backreference count 3, distance 135
    .byte $80, $86
    ; literal count 10; subsequent asset bytes excluded
    .byte $09

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC60
boss_lz_controls_daec60:
    ; backreference count 3, distance 764
    .byte $82, $FB
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

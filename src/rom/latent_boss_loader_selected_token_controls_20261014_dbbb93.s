; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB93
boss_lz_controls_dbbb93:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 21; subsequent asset bytes excluded
    .byte $14

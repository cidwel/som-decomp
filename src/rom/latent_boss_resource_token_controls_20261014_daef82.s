; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF82
boss_lz_controls_daef82:
    ; backreference count 3, distance 16
    .byte $80, $0F
    ; literal count 9; subsequent asset bytes excluded
    .byte $08

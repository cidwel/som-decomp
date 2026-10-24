; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF61
boss_lz_controls_daef61:
    ; backreference count 3, distance 470
    .byte $81, $D5
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

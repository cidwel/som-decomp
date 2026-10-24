; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB09
boss_lz_controls_dadb09:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 105; subsequent asset bytes excluded
    .byte $68

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DB75
boss_lz_controls_dadb75:
    ; backreference count 5, distance 15
    .byte $90, $0E
    ; literal count 59; subsequent asset bytes excluded
    .byte $3A

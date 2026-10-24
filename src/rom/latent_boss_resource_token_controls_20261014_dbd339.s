; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D339
boss_lz_controls_dbd339:
    ; backreference count 4, distance 6
    .byte $84, $05
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

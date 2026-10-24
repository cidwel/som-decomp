; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D580
boss_lz_controls_dbd580:
    ; backreference count 5, distance 460
    .byte $89, $CB
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

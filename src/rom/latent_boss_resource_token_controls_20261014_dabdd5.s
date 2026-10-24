; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDD5
boss_lz_controls_dabdd5:
    ; backreference count 4, distance 254
    .byte $84, $FD
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

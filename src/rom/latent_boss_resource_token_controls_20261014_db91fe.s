; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91FE
boss_lz_controls_db91fe:
    ; backreference count 5, distance 304
    .byte $A1, $2F
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

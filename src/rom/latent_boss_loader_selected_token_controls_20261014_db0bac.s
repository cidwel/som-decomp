; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BAC
boss_lz_controls_db0bac:
    ; backreference count 4, distance 1258
    .byte $94, $E9
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $946C
boss_lz_controls_db946c:
    ; backreference count 3, distance 1121
    .byte $84, $60
    ; literal count 6; subsequent asset bytes excluded
    .byte $05

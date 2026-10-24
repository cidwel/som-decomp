; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07D7
boss_lz_controls_db07d7:
    ; backreference count 7, distance 1395
    .byte $C5, $72
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

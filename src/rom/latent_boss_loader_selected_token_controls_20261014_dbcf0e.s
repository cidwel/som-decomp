; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF0E
boss_lz_controls_dbcf0e:
    ; backreference count 3, distance 1486
    .byte $85, $CD
    ; literal count 35; subsequent asset bytes excluded
    .byte $22

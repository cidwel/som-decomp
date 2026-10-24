; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF0E
boss_lz_controls_dabf0e:
    ; backreference count 3, distance 49
    .byte $80, $30
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

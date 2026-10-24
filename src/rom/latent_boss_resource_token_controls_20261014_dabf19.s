; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF19
boss_lz_controls_dabf19:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

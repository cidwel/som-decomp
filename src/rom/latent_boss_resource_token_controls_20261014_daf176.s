; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F176
boss_lz_controls_daf176:
    ; backreference count 6, distance 1168
    .byte $B4, $8F
    ; backreference count 5, distance 1575
    .byte $A6, $26
    ; backreference count 6, distance 1328
    .byte $B5, $2F
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

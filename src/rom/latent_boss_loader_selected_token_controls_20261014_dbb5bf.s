; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B5BF
boss_lz_controls_dbb5bf:
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; backreference count 4, distance 155
    .byte $84, $9A
    ; literal count 24; subsequent asset bytes excluded
    .byte $17

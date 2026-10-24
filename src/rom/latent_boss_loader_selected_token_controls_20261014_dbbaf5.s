; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAF5
boss_lz_controls_dbbaf5:
    ; backreference count 3, distance 8
    .byte $80, $07
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B

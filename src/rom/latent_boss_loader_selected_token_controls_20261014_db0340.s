; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0340
boss_lz_controls_db0340:
    ; backreference count 3, distance 130
    .byte $80, $81
    ; backreference count 5, distance 339
    .byte $A1, $52
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0484
boss_lz_controls_db0484:
    ; backreference count 6, distance 898
    .byte $B3, $81
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

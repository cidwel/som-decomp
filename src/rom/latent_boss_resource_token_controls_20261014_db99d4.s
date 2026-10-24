; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $99D4
boss_lz_controls_db99d4:
    ; backreference count 4, distance 340
    .byte $91, $53
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

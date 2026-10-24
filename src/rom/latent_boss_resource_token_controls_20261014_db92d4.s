; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $92D4
boss_lz_controls_db92d4:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

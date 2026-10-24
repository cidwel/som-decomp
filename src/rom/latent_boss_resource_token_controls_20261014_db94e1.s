; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $94E1
boss_lz_controls_db94e1:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

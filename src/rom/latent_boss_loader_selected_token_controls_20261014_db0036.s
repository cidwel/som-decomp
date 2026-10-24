; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0036
boss_lz_controls_db0036:
    ; backreference count 3, distance 22
    .byte $80, $15
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

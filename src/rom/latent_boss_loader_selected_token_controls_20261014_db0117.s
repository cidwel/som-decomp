; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0117
boss_lz_controls_db0117:
    ; backreference count 3, distance 252
    .byte $80, $FB
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

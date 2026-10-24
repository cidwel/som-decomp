; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0015
boss_lz_controls_db0015:
    ; backreference count 4, distance 6
    .byte $90, $05
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

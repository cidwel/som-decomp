; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0708
boss_lz_controls_db0708:
    ; backreference count 8, distance 1341
    .byte $D5, $3C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

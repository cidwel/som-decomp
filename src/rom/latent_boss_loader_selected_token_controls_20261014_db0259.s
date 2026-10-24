; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0259
boss_lz_controls_db0259:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 5; subsequent asset bytes excluded
    .byte $04

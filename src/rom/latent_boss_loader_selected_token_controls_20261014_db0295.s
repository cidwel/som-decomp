; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0295
boss_lz_controls_db0295:
    ; backreference count 3, distance 8
    .byte $80, $07
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD36
boss_lz_controls_dbcd36:
    ; backreference count 7, distance 1418
    .byte $C5, $89
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

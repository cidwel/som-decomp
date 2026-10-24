; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CCF1
boss_lz_controls_daccf1:
    ; backreference count 6, distance 640
    .byte $9A, $7F
    ; literal count 99; subsequent asset bytes excluded
    .byte $62

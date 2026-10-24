; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD57
boss_lz_controls_dacd57:
    ; backreference count 11, distance 461
    .byte $C1, $CC
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

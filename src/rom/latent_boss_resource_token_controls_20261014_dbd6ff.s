; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D6FF
boss_lz_controls_dbd6ff:
    ; backreference count 22, distance 351
    .byte $CD, $5E
    ; literal count 17; subsequent asset bytes excluded
    .byte $10

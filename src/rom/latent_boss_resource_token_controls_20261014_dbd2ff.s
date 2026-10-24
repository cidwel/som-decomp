; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2FF
boss_lz_controls_dbd2ff:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

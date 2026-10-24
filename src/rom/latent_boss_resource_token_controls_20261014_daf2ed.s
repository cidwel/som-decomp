; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F2ED
boss_lz_controls_daf2ed:
    ; backreference count 4, distance 1098
    .byte $94, $49
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A

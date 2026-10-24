; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C114
boss_lz_controls_dac114:
    ; backreference count 3, distance 102
    .byte $80, $65
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C

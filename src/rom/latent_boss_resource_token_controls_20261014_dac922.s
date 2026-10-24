; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C922
boss_lz_controls_dac922:
    ; backreference count 3, distance 44
    .byte $80, $2B
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

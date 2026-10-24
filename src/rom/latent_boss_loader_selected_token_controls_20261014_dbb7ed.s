; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7ED
boss_lz_controls_dbb7ed:
    ; backreference count 3, distance 867
    .byte $83, $62
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B154
boss_lz_controls_dbb154:
    ; backreference count 9, distance 911
    .byte $9B, $8E
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B162
boss_lz_controls_dbb162:
    ; backreference count 3, distance 879
    .byte $83, $6E
    ; backreference count 9, distance 958
    .byte $9B, $BD
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

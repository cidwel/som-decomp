; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0FB
boss_lz_controls_dbb0fb:
    ; backreference count 3, distance 157
    .byte $80, $9C
    ; backreference count 5, distance 258
    .byte $89, $01
    ; literal count 8; subsequent asset bytes excluded
    .byte $07

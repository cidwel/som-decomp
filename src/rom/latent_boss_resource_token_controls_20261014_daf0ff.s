; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0FF
boss_lz_controls_daf0ff:
    ; backreference count 3, distance 53
    .byte $80, $34
    ; literal count 2; subsequent asset bytes excluded
    .byte $01

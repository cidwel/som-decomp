; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F12D
boss_lz_controls_daf12d:
    ; backreference count 3, distance 641
    .byte $82, $80
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

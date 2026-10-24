; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B3E7
boss_lz_controls_dbb3e7:
    ; backreference count 3, distance 27
    .byte $80, $1A
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

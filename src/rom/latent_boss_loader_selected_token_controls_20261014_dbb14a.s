; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B14A
boss_lz_controls_dbb14a:
    ; backreference count 4, distance 266
    .byte $85, $09
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B57C
boss_lz_controls_dbb57c:
    ; backreference count 3, distance 392
    .byte $81, $87
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

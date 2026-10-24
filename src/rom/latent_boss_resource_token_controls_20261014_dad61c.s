; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D61C
boss_lz_controls_dad61c:
    ; backreference count 3, distance 440
    .byte $81, $B7
    ; backreference count 4, distance 330
    .byte $89, $49
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D

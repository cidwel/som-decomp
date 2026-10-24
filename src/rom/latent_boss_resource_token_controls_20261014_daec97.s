; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC97
boss_lz_controls_daec97:
    ; backreference count 8, distance 70
    .byte $D0, $45
    ; backreference count 10, distance 71
    .byte $F0, $46
    ; backreference count 10, distance 71
    .byte $F0, $46
    ; literal count 7; subsequent asset bytes excluded
    .byte $06

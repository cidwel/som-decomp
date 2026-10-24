; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF48
boss_lz_controls_daef48:
    ; backreference count 3, distance 1094
    .byte $84, $45
    ; backreference count 3, distance 1203
    .byte $84, $B2
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

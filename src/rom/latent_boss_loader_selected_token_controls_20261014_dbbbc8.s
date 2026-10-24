; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBC8
boss_lz_controls_dbbbc8:
    ; backreference count 3, distance 248
    .byte $80, $F7
    ; backreference count 4, distance 373
    .byte $85, $74
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

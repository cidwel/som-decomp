; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EC7F
boss_lz_controls_daec7f:
    ; backreference count 4, distance 409
    .byte $91, $98
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $086F
boss_lz_controls_db086f:
    ; backreference count 5, distance 3025
    .byte $AB, $D0
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

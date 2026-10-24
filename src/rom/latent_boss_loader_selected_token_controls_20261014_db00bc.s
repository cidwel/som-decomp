; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00BC
boss_lz_controls_db00bc:
    ; backreference count 3, distance 184
    .byte $80, $B7
    ; backreference count 3, distance 6
    .byte $80, $05
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

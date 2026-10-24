; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09BF
boss_lz_controls_db09bf:
    ; backreference count 4, distance 2132
    .byte $98, $53
    ; backreference count 3, distance 8
    .byte $80, $07
    ; backreference count 4, distance 1083
    .byte $94, $3A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

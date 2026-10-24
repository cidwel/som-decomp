; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D65F
boss_lz_controls_dbd65f:
    ; backreference count 4, distance 97
    .byte $84, $60
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

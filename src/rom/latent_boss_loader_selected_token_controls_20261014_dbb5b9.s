; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B5B9
boss_lz_controls_dbb5b9:
    ; backreference count 4, distance 154
    .byte $84, $99
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B685
boss_lz_controls_dab685:
    ; backreference count 10, distance 10
    .byte $9C, $09
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

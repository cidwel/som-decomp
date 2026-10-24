; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECA5
boss_lz_controls_daeca5:
    ; backreference count 3, distance 1077
    .byte $84, $34
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

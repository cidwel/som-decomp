; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F316
boss_lz_controls_daf316:
    ; backreference count 4, distance 1785
    .byte $96, $F8
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

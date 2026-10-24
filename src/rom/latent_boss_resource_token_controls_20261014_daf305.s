; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F305
boss_lz_controls_daf305:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

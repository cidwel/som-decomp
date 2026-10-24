; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B912
boss_lz_controls_dbb912:
    ; backreference count 3, distance 503
    .byte $81, $F6
    ; backreference count 3, distance 662
    .byte $82, $95
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

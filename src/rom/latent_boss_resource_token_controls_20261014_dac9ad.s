; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9AD
boss_lz_controls_dac9ad:
    ; backreference count 4, distance 1158
    .byte $8C, $85
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

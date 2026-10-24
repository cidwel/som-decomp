; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DBD9
boss_lz_controls_dadbd9:
    ; backreference count 3, distance 134
    .byte $80, $85
    ; literal count 3; subsequent asset bytes excluded
    .byte $02

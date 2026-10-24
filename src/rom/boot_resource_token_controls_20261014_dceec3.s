.setcpu "65816"
.segment "CODE"
.org $EEC3
control_dceec3:
    ; backreference count 3, distance 521
    .byte $82, $08
    ; literal count 3; following payload excluded
    .byte $02

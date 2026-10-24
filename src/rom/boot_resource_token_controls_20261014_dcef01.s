.setcpu "65816"
.segment "CODE"
.org $EF01
control_dcef01:
    ; backreference count 7, distance 2
    .byte $90, $01
    ; literal count 3; following payload excluded
    .byte $02

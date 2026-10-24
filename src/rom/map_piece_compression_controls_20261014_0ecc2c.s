.setcpu "65816"
.segment "CODE"
.org $CC2C
map_control_0ecc2c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

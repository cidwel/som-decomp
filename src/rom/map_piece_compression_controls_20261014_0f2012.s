.setcpu "65816"
.segment "CODE"
.org $2012
map_control_0f2012:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $3AC8
map_control_0f3ac8:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

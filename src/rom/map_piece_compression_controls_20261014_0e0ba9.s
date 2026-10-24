.setcpu "65816"
.segment "CODE"
.org $0BA9
map_control_0e0ba9:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $0024
map_control_0f0024:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

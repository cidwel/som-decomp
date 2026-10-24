.setcpu "65816"
.segment "CODE"
.org $0F92
map_control_0f0f92:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

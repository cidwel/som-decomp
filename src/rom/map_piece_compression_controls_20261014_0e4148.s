.setcpu "65816"
.segment "CODE"
.org $4148
map_control_0e4148:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

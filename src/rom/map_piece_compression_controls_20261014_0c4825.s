.setcpu "65816"
.segment "CODE"
.org $4825
map_control_0c4825:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

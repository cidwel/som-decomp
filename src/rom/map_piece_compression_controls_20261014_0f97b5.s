.setcpu "65816"
.segment "CODE"
.org $97B5
map_control_0f97b5:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

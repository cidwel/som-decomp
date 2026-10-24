.setcpu "65816"
.segment "CODE"
.org $44B9
map_control_0c44b9:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

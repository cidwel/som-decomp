.setcpu "65816"
.segment "CODE"
.org $B9BE
map_control_0eb9be:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

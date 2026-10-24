.setcpu "65816"
.segment "CODE"
.org $3F7A
map_control_0c3f7a:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

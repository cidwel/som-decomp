.setcpu "65816"
.segment "CODE"
.org $92A2
map_control_0d92a2:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

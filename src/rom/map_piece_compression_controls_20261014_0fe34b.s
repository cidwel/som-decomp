.setcpu "65816"
.segment "CODE"
.org $E34B
map_control_0fe34b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $661C
map_control_0e661c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

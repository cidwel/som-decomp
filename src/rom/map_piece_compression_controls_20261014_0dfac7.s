.setcpu "65816"
.segment "CODE"
.org $FAC7
map_control_0dfac7:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

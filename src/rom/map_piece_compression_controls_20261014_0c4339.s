.setcpu "65816"
.segment "CODE"
.org $4339
map_control_0c4339:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

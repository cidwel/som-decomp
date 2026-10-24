.setcpu "65816"
.segment "CODE"
.org $6523
map_control_0f6523:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

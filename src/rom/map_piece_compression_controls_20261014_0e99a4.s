.setcpu "65816"
.segment "CODE"
.org $99A4
map_control_0e99a4:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

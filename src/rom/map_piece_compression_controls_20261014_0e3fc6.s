.setcpu "65816"
.segment "CODE"
.org $3FC6
map_control_0e3fc6:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

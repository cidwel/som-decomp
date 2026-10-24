.setcpu "65816"
.segment "CODE"
.org $B6E6
map_control_0db6e6:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

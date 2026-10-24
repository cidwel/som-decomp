.setcpu "65816"
.segment "CODE"
.org $B9E6
map_control_0db9e6:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

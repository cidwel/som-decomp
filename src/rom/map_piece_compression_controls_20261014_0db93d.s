.setcpu "65816"
.segment "CODE"
.org $B93D
map_control_0db93d:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2490
map_control_0d2490:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $973F
map_control_0f973f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $FAC2
map_control_0dfac2:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

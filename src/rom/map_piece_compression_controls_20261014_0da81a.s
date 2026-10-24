.setcpu "65816"
.segment "CODE"
.org $A81A
map_control_0da81a:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

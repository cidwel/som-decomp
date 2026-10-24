.setcpu "65816"
.segment "CODE"
.org $E6F2
map_control_0ee6f2:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

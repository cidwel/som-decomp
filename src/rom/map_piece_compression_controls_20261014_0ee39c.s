.setcpu "65816"
.segment "CODE"
.org $E39C
map_control_0ee39c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

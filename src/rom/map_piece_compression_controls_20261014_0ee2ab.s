.setcpu "65816"
.segment "CODE"
.org $E2AB
map_control_0ee2ab:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

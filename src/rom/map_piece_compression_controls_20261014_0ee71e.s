.setcpu "65816"
.segment "CODE"
.org $E71E
map_control_0ee71e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

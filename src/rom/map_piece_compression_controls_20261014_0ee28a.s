.setcpu "65816"
.segment "CODE"
.org $E28A
map_control_0ee28a:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

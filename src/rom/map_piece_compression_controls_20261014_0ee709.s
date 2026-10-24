.setcpu "65816"
.segment "CODE"
.org $E709
map_control_0ee709:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

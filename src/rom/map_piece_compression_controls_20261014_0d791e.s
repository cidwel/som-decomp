.setcpu "65816"
.segment "CODE"
.org $791E
map_control_0d791e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

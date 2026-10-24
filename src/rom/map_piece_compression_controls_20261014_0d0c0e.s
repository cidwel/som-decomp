.setcpu "65816"
.segment "CODE"
.org $0C0E
map_control_0d0c0e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

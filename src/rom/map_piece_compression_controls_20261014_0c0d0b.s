.setcpu "65816"
.segment "CODE"
.org $0D0B
map_control_0c0d0b:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

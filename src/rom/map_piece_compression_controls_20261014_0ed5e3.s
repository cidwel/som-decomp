.setcpu "65816"
.segment "CODE"
.org $D5E3
map_control_0ed5e3:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

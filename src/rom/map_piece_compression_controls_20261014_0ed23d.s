.setcpu "65816"
.segment "CODE"
.org $D23D
map_control_0ed23d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2C74
map_control_0c2c74:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

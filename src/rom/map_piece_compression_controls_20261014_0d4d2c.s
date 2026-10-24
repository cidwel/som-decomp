.setcpu "65816"
.segment "CODE"
.org $4D2C
map_control_0d4d2c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

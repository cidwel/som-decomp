.setcpu "65816"
.segment "CODE"
.org $45E6
map_control_0c45e6:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

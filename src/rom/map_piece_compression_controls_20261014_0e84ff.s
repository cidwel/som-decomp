.setcpu "65816"
.segment "CODE"
.org $84FF
map_control_0e84ff:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

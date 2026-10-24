.setcpu "65816"
.segment "CODE"
.org $0C65
map_control_0e0c65:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

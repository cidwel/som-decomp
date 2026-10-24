.setcpu "65816"
.segment "CODE"
.org $0010
map_control_0f0010:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

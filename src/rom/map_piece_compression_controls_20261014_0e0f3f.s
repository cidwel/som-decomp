.setcpu "65816"
.segment "CODE"
.org $0F3F
map_control_0e0f3f:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

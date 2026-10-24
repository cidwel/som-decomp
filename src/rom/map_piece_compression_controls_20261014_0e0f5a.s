.setcpu "65816"
.segment "CODE"
.org $0F5A
map_control_0e0f5a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

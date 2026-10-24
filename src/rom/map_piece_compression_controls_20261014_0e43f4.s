.setcpu "65816"
.segment "CODE"
.org $43F4
map_control_0e43f4:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

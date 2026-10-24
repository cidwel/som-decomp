.setcpu "65816"
.segment "CODE"
.org $1CC4
map_control_0f1cc4:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $FA7A
map_control_0cfa7a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

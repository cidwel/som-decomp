.setcpu "65816"
.segment "CODE"
.org $810A
map_control_0f810a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

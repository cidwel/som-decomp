.setcpu "65816"
.segment "CODE"
.org $EEC4
map_control_0feec4:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

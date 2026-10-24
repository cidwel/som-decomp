.setcpu "65816"
.segment "CODE"
.org $3F83
map_control_0c3f83:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

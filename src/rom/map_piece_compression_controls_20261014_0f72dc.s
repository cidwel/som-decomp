.setcpu "65816"
.segment "CODE"
.org $72DC
map_control_0f72dc:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $FBC7
map_control_0ffbc7:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

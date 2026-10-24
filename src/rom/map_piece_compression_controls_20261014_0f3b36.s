.setcpu "65816"
.segment "CODE"
.org $3B36
map_control_0f3b36:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

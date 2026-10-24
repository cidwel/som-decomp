.setcpu "65816"
.segment "CODE"
.org $BB89
map_control_0dbb89:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $440B
map_control_0e440b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

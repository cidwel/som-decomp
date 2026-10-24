.setcpu "65816"
.segment "CODE"
.org $D673
map_control_0dd673:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

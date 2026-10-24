.setcpu "65816"
.segment "CODE"
.org $905B
map_control_0c905b:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

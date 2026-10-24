.setcpu "65816"
.segment "CODE"
.org $6174
map_control_0e6174:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $754F
map_control_0e754f:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

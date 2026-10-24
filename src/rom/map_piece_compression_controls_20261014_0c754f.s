.setcpu "65816"
.segment "CODE"
.org $754F
map_control_0c754f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

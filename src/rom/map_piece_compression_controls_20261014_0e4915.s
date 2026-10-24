.setcpu "65816"
.segment "CODE"
.org $4915
map_control_0e4915:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

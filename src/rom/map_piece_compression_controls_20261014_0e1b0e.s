.setcpu "65816"
.segment "CODE"
.org $1B0E
map_control_0e1b0e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $1B1C
map_control_0e1b1c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

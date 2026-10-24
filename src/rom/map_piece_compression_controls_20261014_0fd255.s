.setcpu "65816"
.segment "CODE"
.org $D255
map_control_0fd255:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

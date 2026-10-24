.setcpu "65816"
.segment "CODE"
.org $FD8F
map_control_0dfd8f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

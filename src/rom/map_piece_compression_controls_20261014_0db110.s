.setcpu "65816"
.segment "CODE"
.org $B110
map_control_0db110:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $AD9A
map_control_0dad9a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $6F9A
map_control_0c6f9a:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $4859
map_control_0c4859:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

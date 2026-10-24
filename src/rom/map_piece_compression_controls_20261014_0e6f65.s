.setcpu "65816"
.segment "CODE"
.org $6F65
map_control_0e6f65:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

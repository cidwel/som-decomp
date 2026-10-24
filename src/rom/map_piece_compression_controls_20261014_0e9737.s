.setcpu "65816"
.segment "CODE"
.org $9737
map_control_0e9737:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

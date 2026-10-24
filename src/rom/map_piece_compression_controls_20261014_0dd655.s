.setcpu "65816"
.segment "CODE"
.org $D655
map_control_0dd655:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

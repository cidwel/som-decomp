.setcpu "65816"
.segment "CODE"
.org $26C7
map_control_0d26c7:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

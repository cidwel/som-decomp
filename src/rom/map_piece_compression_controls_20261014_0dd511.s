.setcpu "65816"
.segment "CODE"
.org $D511
map_control_0dd511:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count

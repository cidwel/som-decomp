.setcpu "65816"
.segment "CODE"
.org $7486
map_control_0c7486:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

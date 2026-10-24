.setcpu "65816"
.segment "CODE"
.org $95AB
map_control_0f95ab:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

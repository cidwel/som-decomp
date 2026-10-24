.setcpu "65816"
.segment "CODE"
.org $0EB4
map_control_0d0eb4:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

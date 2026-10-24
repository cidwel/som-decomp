.setcpu "65816"
.segment "CODE"
.org $D521
map_control_0dd521:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count

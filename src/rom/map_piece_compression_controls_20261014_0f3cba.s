.setcpu "65816"
.segment "CODE"
.org $3CBA
map_control_0f3cba:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

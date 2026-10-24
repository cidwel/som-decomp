.setcpu "65816"
.segment "CODE"
.org $5AE9
map_control_0f5ae9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

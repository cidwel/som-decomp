.setcpu "65816"
.segment "CODE"
.org $20F4
map_control_0f20f4:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

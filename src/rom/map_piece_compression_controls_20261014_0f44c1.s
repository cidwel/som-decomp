.setcpu "65816"
.segment "CODE"
.org $44C1
map_control_0f44c1:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

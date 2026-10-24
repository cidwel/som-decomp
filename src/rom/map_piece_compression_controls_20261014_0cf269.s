.setcpu "65816"
.segment "CODE"
.org $F269
map_control_0cf269:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $DA ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $7F39
map_control_0c7f39:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

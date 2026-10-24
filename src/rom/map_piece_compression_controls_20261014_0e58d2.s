.setcpu "65816"
.segment "CODE"
.org $58D2
map_control_0e58d2:
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count

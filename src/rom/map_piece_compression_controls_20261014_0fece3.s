.setcpu "65816"
.segment "CODE"
.org $ECE3
map_control_0fece3:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

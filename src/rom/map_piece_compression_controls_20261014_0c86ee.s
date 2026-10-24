.setcpu "65816"
.segment "CODE"
.org $86EE
map_control_0c86ee:
    .byte $EE ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

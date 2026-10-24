.setcpu "65816"
.segment "CODE"
.org $7018
map_control_0c7018:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $8180
map_control_0f8180:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count

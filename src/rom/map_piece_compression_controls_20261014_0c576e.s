.setcpu "65816"
.segment "CODE"
.org $576E
map_control_0c576e:
    .byte $D9 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count

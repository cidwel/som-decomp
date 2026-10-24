.setcpu "65816"
.segment "CODE"
.org $0C7E
map_control_0c0c7e:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

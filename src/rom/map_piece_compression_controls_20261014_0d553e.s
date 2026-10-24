.setcpu "65816"
.segment "CODE"
.org $553E
map_control_0d553e:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

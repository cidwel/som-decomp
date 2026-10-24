.setcpu "65816"
.segment "CODE"
.org $D742
map_control_0fd742:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

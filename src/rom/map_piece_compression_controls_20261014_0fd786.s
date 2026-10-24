.setcpu "65816"
.segment "CODE"
.org $D786
map_control_0fd786:
    .byte $D1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count

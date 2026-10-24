.setcpu "65816"
.segment "CODE"
.org $9966
map_control_0f9966:
    .byte $ED ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

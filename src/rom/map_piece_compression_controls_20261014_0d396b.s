.setcpu "65816"
.segment "CODE"
.org $396B
map_control_0d396b:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

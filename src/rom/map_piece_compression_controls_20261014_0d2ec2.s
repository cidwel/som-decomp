.setcpu "65816"
.segment "CODE"
.org $2EC2
map_control_0d2ec2:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

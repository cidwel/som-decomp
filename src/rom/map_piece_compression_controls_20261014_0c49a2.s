.setcpu "65816"
.segment "CODE"
.org $49A2
map_control_0c49a2:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count

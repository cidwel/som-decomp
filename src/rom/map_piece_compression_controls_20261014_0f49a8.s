.setcpu "65816"
.segment "CODE"
.org $49A8
map_control_0f49a8:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

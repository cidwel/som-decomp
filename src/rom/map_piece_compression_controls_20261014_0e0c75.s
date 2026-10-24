.setcpu "65816"
.segment "CODE"
.org $0C75
map_control_0e0c75:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

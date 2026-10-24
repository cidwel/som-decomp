.setcpu "65816"
.segment "CODE"
.org $0C31
map_control_0f0c31:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

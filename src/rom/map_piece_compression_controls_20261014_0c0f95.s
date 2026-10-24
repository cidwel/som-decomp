.setcpu "65816"
.segment "CODE"
.org $0F95
map_control_0c0f95:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count

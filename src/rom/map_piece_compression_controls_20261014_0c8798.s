.setcpu "65816"
.segment "CODE"
.org $8798
map_control_0c8798:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CA ; same-value copy count/distance

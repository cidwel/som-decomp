.setcpu "65816"
.segment "CODE"
.org $4CA8
map_control_0f4ca8:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count

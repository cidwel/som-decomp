.setcpu "65816"
.segment "CODE"
.org $4867
map_control_0e4867:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $2162
map_control_0c2162:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

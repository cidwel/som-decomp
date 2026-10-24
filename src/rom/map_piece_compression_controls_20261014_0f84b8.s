.setcpu "65816"
.segment "CODE"
.org $84B8
map_control_0f84b8:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

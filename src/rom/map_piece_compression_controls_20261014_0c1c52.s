.setcpu "65816"
.segment "CODE"
.org $1C52
map_control_0c1c52:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $CA ; same-value copy count/distance

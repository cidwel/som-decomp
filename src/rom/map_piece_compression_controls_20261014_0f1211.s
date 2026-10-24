.setcpu "65816"
.segment "CODE"
.org $1211
map_control_0f1211:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance

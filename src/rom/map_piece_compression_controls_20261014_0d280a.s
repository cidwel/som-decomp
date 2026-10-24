.setcpu "65816"
.segment "CODE"
.org $280A
map_control_0d280a:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

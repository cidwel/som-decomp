.setcpu "65816"
.segment "CODE"
.org $20F7
map_control_0f20f7:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count

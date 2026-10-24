.setcpu "65816"
.segment "CODE"
.org $28B1
map_control_0c28b1:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $A4E4
map_control_0fa4e4:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

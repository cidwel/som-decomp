.setcpu "65816"
.segment "CODE"
.org $4708
map_control_0c4708:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

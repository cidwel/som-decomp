.setcpu "65816"
.segment "CODE"
.org $7FCB
map_control_0c7fcb:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

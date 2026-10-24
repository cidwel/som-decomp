.setcpu "65816"
.segment "CODE"
.org $43A4
map_control_0c43a4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

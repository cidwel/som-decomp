.setcpu "65816"
.segment "CODE"
.org $5671
map_control_0d5671:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

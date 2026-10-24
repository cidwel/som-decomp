.setcpu "65816"
.segment "CODE"
.org $8816
map_control_0c8816:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

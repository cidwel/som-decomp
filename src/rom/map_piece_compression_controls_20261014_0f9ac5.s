.setcpu "65816"
.segment "CODE"
.org $9AC5
map_control_0f9ac5:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count

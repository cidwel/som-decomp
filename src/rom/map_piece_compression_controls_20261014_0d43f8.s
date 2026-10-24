.setcpu "65816"
.segment "CODE"
.org $43F8
map_control_0d43f8:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count

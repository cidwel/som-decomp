.setcpu "65816"
.segment "CODE"
.org $019D
map_control_0f019d:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

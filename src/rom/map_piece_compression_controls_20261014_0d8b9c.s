.setcpu "65816"
.segment "CODE"
.org $8B9C
map_control_0d8b9c:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count

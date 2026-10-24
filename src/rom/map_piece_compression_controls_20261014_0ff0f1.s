.setcpu "65816"
.segment "CODE"
.org $F0F1
map_control_0ff0f1:
    .byte $D7 ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count

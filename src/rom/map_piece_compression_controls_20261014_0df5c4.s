.setcpu "65816"
.segment "CODE"
.org $F5C4
map_control_0df5c4:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $EEB8
map_control_0eeeb8:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

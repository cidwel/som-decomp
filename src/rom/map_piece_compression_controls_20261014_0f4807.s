.setcpu "65816"
.segment "CODE"
.org $4807
map_control_0f4807:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

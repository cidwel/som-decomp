.setcpu "65816"
.segment "CODE"
.org $EF1B
map_control_0fef1b:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

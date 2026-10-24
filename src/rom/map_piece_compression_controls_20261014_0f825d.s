.setcpu "65816"
.segment "CODE"
.org $825D
map_control_0f825d:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

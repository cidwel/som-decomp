.setcpu "65816"
.segment "CODE"
.org $C852
map_control_0ec852:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

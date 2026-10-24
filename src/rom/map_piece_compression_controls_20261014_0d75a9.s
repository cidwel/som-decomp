.setcpu "65816"
.segment "CODE"
.org $75A9
map_control_0d75a9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

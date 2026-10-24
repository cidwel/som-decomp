.setcpu "65816"
.segment "CODE"
.org $4214
map_control_0f4214:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

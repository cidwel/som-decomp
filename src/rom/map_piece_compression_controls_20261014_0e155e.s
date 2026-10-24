.setcpu "65816"
.segment "CODE"
.org $155E
map_control_0e155e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $0FE3
map_control_0f0fe3:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance

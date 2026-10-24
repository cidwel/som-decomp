.setcpu "65816"
.segment "CODE"
.org $78A1
map_control_0f78a1:
    .byte $D2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

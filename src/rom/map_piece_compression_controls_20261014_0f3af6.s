.setcpu "65816"
.segment "CODE"
.org $3AF6
map_control_0f3af6:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count

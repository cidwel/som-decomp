.setcpu "65816"
.segment "CODE"
.org $43F5
map_control_0f43f5:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance

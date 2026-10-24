.setcpu "65816"
.segment "CODE"
.org $615A
map_control_0f615a:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count

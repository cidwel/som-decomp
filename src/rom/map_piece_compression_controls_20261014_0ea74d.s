.setcpu "65816"
.segment "CODE"
.org $A74D
map_control_0ea74d:
    .byte $C4 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $D675
map_control_0fd675:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count

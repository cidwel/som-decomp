.setcpu "65816"
.segment "CODE"
.org $54FA
map_control_0f54fa:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

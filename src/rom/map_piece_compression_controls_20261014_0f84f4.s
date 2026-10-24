.setcpu "65816"
.segment "CODE"
.org $84F4
map_control_0f84f4:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $49AC
map_control_0f49ac:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

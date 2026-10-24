.setcpu "65816"
.segment "CODE"
.org $374B
map_control_0f374b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
